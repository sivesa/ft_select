#include <sys/ioctl.h>
#include "ft_select.h"

void		goto_prec(t_list *root)
{
	t_list	*tmp;

	if (root->nb_elem != 1)
	{
		tmp = root->next;
		while (tmp && tmp->is_current == 0)
			tmp = tmp->next;
		if (tmp->prec != root)
			tmp->prec->is_current = 1;
		else
			tmp->prec->prec->is_current = 1;
		tmp->is_current = 0;
		clearscreen(root);
		print_list(root);
	}
}

void		goto_next(t_list *root)
{
	t_list	*tmp;

	if (root->nb_elem != 1)
	{
		tmp = root->next;
		while (tmp && tmp->is_current == 0)
			tmp = tmp->next;
		tmp->is_current = 0;
		if (tmp->next != root)
			tmp->next->is_current = 1;
		else
			tmp->next->next->is_current = 1;
		clearscreen(root);
		print_list(root);
	}
}

void			goto_left(t_list *root)
{
	struct winsize	win;
	t_list		*tmp;
	int			i;

	i = 0;
	if ((ioctl(fd_tty, TIOCGWINSZ, &win)) == -1)
		return ;
	if (root->nb_elem != 1 && win.ws_row < root->nb_elem)
	{
		tmp = root->next;
		while (tmp && tmp->is_current == 0 && ++i)
			tmp = tmp->next;
		if (i < win.ws_row - 1)
			return ;
		i = 1;
		tmp->is_current = 0;
		while (i++ < win.ws_row)
			tmp = tmp->prec;
		tmp->is_current = 1;
		clearscreen(root);
		print_list(root);
	}
}

void			goto_right(t_list *root)
{
	struct winsize	win;
	t_list		*tmp;
	int			i;

	i = 0;
	if ((ioctl(fd_tty, TIOCGWINSZ, &win)) == -1)
		return ;
	if (root->nb_elem != 1 && win.ws_row < root->nb_elem)
	{
		tmp = root->next;
		while (tmp && tmp->is_current == 0 && ++i)
			tmp = tmp->next;
		if (i > root->nb_elem - win.ws_row)
			return ;
		i = 1;
		tmp->is_current = 0;
		while (tmp != root && i++ < win.ws_row)
			tmp = tmp->next;
		tmp->is_current = 1;
		clearscreen(root);
		print_list(root);
	}
}

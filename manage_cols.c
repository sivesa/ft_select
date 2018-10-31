#include <sys/ioctl.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "ft_select.h"

static int	get_size_from_to(int begin, int end, t_list *root)
{
	t_list	*tmp;
	int		size_max;
	int		i;

	i = 0;
	tmp = root;
	size_max = 0;
	while (i <= begin)
	{
		tmp = tmp->next;
		i++;
	}
	while (i <= end)
	{
		if (tmp->size_str > size_max)
			size_max = tmp->size_str;
		tmp = tmp->next;
		i = i + 1;
	}
	if (tmp->size_str > size_max)
		size_max = tmp->size_str;
	return (size_max);
}

static int	get_size_max(int i, int ws_row, t_list *root)
{
	int		j;
	int		num_col;
	int		size_max;
	int		col_total;

	j = 0;
	size_max = 0;
	col_total = (root->nb_elem) / ws_row;
	num_col = i / ws_row;
	while (j < num_col)
	{
		size_max += get_size_from_to(ws_row * j, (ws_row * (j + 1) - 1), root);
		j = j + 1;
	}
	return (size_max);
}

static int	get_size_elem(t_list *root, int i)
{
	t_list	*tmp;
	int		counter;

	counter = 0;
	tmp = root->next;
	while (counter < i)
		counter += 1;
	return (tmp->size_str + 1);
}

int			manage_col(int i, t_list *root)
{
	struct winsize	win;
	int			nb_lines;
	int			row;
	int			tmp;

	nb_lines = 0;
	ioctl(fd_tty, TIOCGWINSZ, &win);
	win.ws_row -= 1;
	if (win.ws_row == 0
	|| get_size_from_to(0, root->nb_elem - 1, root) > win.ws_col
	|| ((row = get_size_max(i, win.ws_row, root))
	  + get_size_elem(root, i) > win.ws_col))
	{
		ft_tputs(tgetstr("cl", NULL));
		ft_tputs(tgoto(tgetstr("cm", NULL), 0, 0));
		ft_tputs("Window is too little, please resize it\n");
		return (-1);
	}
	if (i >= win.ws_row)
		ft_tputs(tgoto(tgetstr("cm", NULL), row, i % (win.ws_row)));
	return (0);
}

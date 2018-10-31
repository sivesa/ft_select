#include <curses.h>
#include <term.h>
#include "ft_select.h"

static void	puts_select(char *str)
{
	ft_tputs(tgetstr("so", NULL));
	ft_tputs(str);
	ft_tputs(tgetstr("se", NULL));
}

static void	puts_current(char *str)
{
	ft_tputs(tgetstr("us", NULL));
	ft_tputs(str);
	ft_tputs(tgetstr("ue", NULL));
}

static void	puts_two(char *str)
{
	ft_tputs(tgetstr("so", NULL));
	ft_tputs(tgetstr("us", NULL));
	ft_tputs(str);
	ft_tputs(tgetstr("ue", NULL));
	ft_tputs(tgetstr("se", NULL));
}

void		print_list(t_list *root)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = root->next;
	ft_tputs(tgoto(tgetstr("cm", NULL), 0, 0));
	while (tmp != root)
	{
		if ((manage_col(i, root)) == -1)
			return ;
		if (tmp->is_select == 1 && tmp->is_current == 0)
			puts_select(tmp->str);
		else if (tmp->is_current == 1 && tmp->is_select == 0)
			puts_current(tmp->str);
		else if (tmp->is_current == 1 && tmp->is_select == 1)
			puts_two(tmp->str);
		else
			ft_tputs(tmp->str);
		ft_putchar('\n');
		i++;
		tmp = tmp->next;
	}
}

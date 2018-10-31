#include <curses.h>
#include <term.h>
#include "ft_select.h"

void	clearscreen(t_list *root)
{
	int	i;

	i = 0;
	while (i < root->nb_elem)
	{
		ft_tputs(tgetstr("up", NULL));
		i = i + 1;
	}
	i = 0;
	while (i < root->nb_elem)
	{
		ft_tputs(tgetstr("dl", NULL));
		i = i + 1;
	}
}

#include <unistd.h>
#include "ft_select.h"

int		is_last(t_list *tmp, t_list *root)
{
	tmp = tmp->next;
	while (tmp != root)
	{
		if (tmp->is_select == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		disp_select(t_list *root)
{
	t_list	*tmp;

	tmp = root->next;
	while (tmp != root)
	{
		if (tmp->is_select == 1)
		{
			ft_putstr(tmp->str);
			if (is_last(tmp, root) == 0)
				write(1, " ", 1);
		}
		tmp = tmp->next;
	}
}

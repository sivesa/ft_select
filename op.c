#include <stdlib.h>
#include "ft_select.h"

void		select_it(t_list *root)
{
	t_list	*tmp;

	tmp = root->next;
	while (tmp && tmp->is_current == 0)
		tmp = tmp->next;
	if (tmp->is_select == 1)
		tmp->is_select = 0;
	else
	{
		tmp->is_select = 1;
		tmp->is_current = 0;
		if (tmp->next != root)
		tmp->next->is_current = 1;
		else
		tmp->next->next->is_current = 1;
	}
	clearscreen(root);
	print_list(root);
}

void		rm_it(t_list *root)
{
	t_list	*tmp;

	if (root->nb_elem != 1)
	{
		tmp = root->next;
		while (tmp && tmp->is_current == 0)
			tmp = tmp->next;
		tmp->prec->next = tmp->next;
		tmp->next->prec = tmp->prec;
		if (tmp->next != root)
			tmp->next->is_current = 1;
		else
			tmp->next->next->is_current = 1;
		clearscreen(root);
		root->nb_elem = root->nb_elem - 1;
		free(tmp);
		print_list(root);
	}
}

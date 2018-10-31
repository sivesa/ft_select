#include <stdlib.h>
#include "ft_select.h"

static t_list	*create_list(char *str)
{
	t_list	*new;

	new = NULL;
	if (new = (t_list*)malloc(sizeof(*new)))
	{
		new->str = str;
		new->size_str = ft_strlen(str) + 2;
		new->is_select = 0;
		new->is_current = 0;
		new->prec = NULL;
		new->next = NULL;
	}
	else
		puterror("error: could not allocate memory\n");
	return (new);
}

int		push_back(t_list **root, char *str)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *root;
	new = create_list(str);
	if (new)
	{
		new->prec = tmp->prec;
		new->next = tmp;
		tmp->prec->next = new;
		tmp->prec = new;
		(*root)->nb_elem = (*root)->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int	init_roots(t_list **root)
{
	if ((*root = (t_list*)malloc(sizeof(**root))) == NULL)
	{
		puterror("error: could not allocate memory\n");
		return (-1);
	}
	(*root)->is_current = 0;
	(*root)->is_select = 0;
	(*root)->nb_elem = 0;
	(*root)->next = (*root);
	(*root)->prec = (*root);
	return (0);
}

void		free_list(t_list *root)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = root->next;
	while (tmp != root)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
}

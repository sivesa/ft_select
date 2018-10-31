#include <stdlib.h>
#include "ft_select.h"

static t_func	*create_func(char *keycode,
			     void (*func_ptr)(t_list *root))
{
	t_func	*new;

	new = NULL;
	if ((new = (t_func*)malloc(sizeof(*new))))
	{
		new->keycode = keycode;
		new->func_ptr = func_ptr;
		new->next = NULL;
	}
	return (new);
}

static int	push_func(t_func **list, char *keycode,
			  void (*func_ptr)(t_list *root))
{
	t_func	*tmp;

	tmp = *list;
	if (*list)
	{
		while (tmp->next)
			tmp = tmp->next;
		if ((tmp->next = create_func(keycode, func_ptr)))
			return (0);
	}
	else if ((*list = create_func(keycode, func_ptr)))
		return (0);
	puterror("error: could not alloc\n");
	return (-1);
}

static char	*get_keycode(int i)
{
	char		*keycode;

	keycode = NULL;
	(i == 0) ? (keycode = init_prec()) : (0);
	(i == 1) ? (keycode = init_next()) : (0);
	(i == 2) ? (keycode = init_left()) : (0);
	(i == 3) ? (keycode = init_right()) : (0);
	(i == 4) ? (keycode = init_select()) : (0);
	(i == 5) ? (keycode = init_rm_backspace()) : (0);
	(i == 6) ? (keycode = init_rm_del()) : (0);
	return (keycode);
}

static void	get_func(void (**func_ptr)(t_list *root), int i)
{
	(i == 0) ? (*func_ptr = &goto_prec) : (0);
	(i == 1) ? (*func_ptr = &goto_next) : (0);
	(i == 2) ? (*func_ptr = &goto_left) : (0);
	(i == 3) ? (*func_ptr = &goto_right) : (0);
	(i == 4) ? (*func_ptr = &select_it) : (0);
	(i == 5) ? (*func_ptr = &rm_it) : (0);
	(i == 6) ? (*func_ptr = &rm_it) : (0);
}

t_func		*init_func(void)
{
	t_func	*list_func;
	int		i;
	char		*keycode;
	void		(*func_ptr)(t_list *root);

	i = 0;
	list_func = NULL;
	while (i < 7)
	{
		get_func(&func_ptr, i);
		if ((keycode = get_keycode(i)) == NULL)
			return (NULL);
		if ((push_func(&list_func, keycode, func_ptr)) == -1)
			return (NULL);
		i++;
	}
	return (list_func);
}

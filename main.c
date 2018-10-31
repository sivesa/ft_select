#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_select.h"

static int	get_arg(int argc, char **argv, t_list **root)
{
	t_list	*tmp;
	int		i;

	i = 1;
	if (argc == 1)
		return (usage());
	if ((init_roots(root)) == -1)
		return (-1);
	tmp = *root;
	while (argv[i])
	{
		if ((push_back(&tmp, argv[i])) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv, char **env)
{
	struct termios	term_attr;

	root_args = NULL;
	if ((fd_tty = open("/dev/tty", O_RDWR)) == -1)
		return (puterror("error: could not open /dev/tty\n"));
	if (get_arg(argc, argv, &root_args) == -1)
		return (-1);
	if ((init_term(env, &term_attr)) == -1)
		return (-1);
	signal(SIGWINCH, get_sigwinch);
	if ((get_cmd()) == -1)
		return (-1);
	restore_term(&term_attr);
	disp_select(root_args);
	free_list(root_args);
	return (0);
}

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "ft_select.h"

void			get_sigwinch(int sig)
{
	ft_tputs(tgetstr("cl", NULL));
	print_list(root_args);
}

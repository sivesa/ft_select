#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "ft_select.h"

/*
 * This function initiates the terminal
 */
int	init_term(char **env,
		   struct termios *term_attr)
{
	char	term_buf[TERM_BUF_SIZE];
	char	*term_name;

	if ((term_name = get_term(env)) == NULL)
		term_name = "xterm";
	if ((tgetent(term_buf, term_name)) <= 0)
	{
		puterror("error: could not find termcap database or \"");
		puterror(term_name);
		puterror("\" is not specified\n");
		return (-1);
	}
	if ((tcgetattr(0, term_attr)) < 0) /* */
		return (puterror("error: could not get term values\n"));
	term_attr->c_lflag &= ~ICANON; 			/* ICANON - enables canonical mode*/
	term_attr->c_lflag &= ~ECHO; 				/* ECHO - input characters */
	term_attr->c_cc[VMIN] = 1; 				/* The  c_cc  array defines the terminal special characters. 
										   VMIN Minimum number of characters for noncanonical read (MIN)*/
	term_attr->c_cc[VTIME] = 0; 				/*VTIME Timeout in deciseconds for noncanonical read (TIME). */
	if (tcsetattr(0, TCSANOW, term_attr) < 0) 	/* optional_actions specifies when the changes take effect */
		return (puterror("error: could not set term values\n"));
	ft_tputs(tgetstr("vi", NULL)); 			/*The tgetstr() function gets the string entry for id. If area is not a null pointer and does not
										  point to a null pointer, tgetstr() copies the string entry into the buffer pointed to by *area
										  and advances the variable pointed to by area to the first byte after the copy of the string
										  entry. */

	ft_tputs(tgetstr("cl", NULL));
	root_args->next->is_current = 1;
	print_list(root_args);
	return (0);
}

int	restore_term(struct termios *term_attr)
{
	clearscreen(root_args);
	term_attr->c_lflag |= ICANON;
	term_attr->c_lflag |= ECHO;
	if ((tcsetattr(0, TCSANOW, term_attr)) == -1)
		return (puterror("error: could not set term values\n"));
	ft_tputs(tgetstr("ve", NULL));
	if ((close(fd_tty)) == -1)
		return (puterror("error: could not close /dev/tty\n"));
}

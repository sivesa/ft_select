#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

int	puterror(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		write(2, &str[i++], 1);
	return (-1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_tputs(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		puterror("error: problem with function tgetstr or tgoto\n");
		exit(EXIT_FAILURE);
	}
	while (str[i])
		write(fd_tty, &str[i++], 1);
}

void	ft_putchar(char c)
{
	write(fd_tty, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

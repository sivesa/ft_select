#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	size;

	size = 0;
	if (s == NULL)
		return (0);
	while (s[size])
		size = size + 1;
	return (size);
}

char	*get_term(char **env)
{
	int	i;
	char	*ptr;

	i = 0;
	if (env == NULL || env[0] == NULL)
		return (NULL);
	while (env[i])
	{
		if (env[i][0] == 'T' && env[i][1] == 'E' && env[i][2] == 'R'
		&& env[i][3] == 'M' && env[i][4] == '=')
			return (&(env[i][5]));
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	return ((*s1 == *s2 && *s1) ? (ft_strcmp(++s1, ++s2)) : (*s1 - *s2));
}

void	buf_zero(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i = i + 1;
	}
}

int	usage(void)
{
	if ((close(fd_tty)) == -1)
		ft_putstr("error: could not close\n");
	ft_putstr("usage: ./ft_select choice1 choice2 [...]\n");
	return (-1);
}

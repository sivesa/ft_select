#include <stdlib.h>
#include "ft_select.h"

char	*init_select(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(2))
	{
		keycode[0] = 32;
		keycode[1] = 0;
	}
	return (keycode);
}

char	*init_rm_backspace(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(2))
	{
		keycode[0] = 127;
		keycode[1] = 0;
	}
	return (keycode);
}

char	*init_rm_del(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(5))
	{
		keycode[0] = 27;
		keycode[1] = 91;
		keycode[2] = 51;
		keycode[3] = 126;
		keycode[4] = 0;
	}
	return (keycode);
}

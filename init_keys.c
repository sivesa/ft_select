#include <stdlib.h>

char	*init_prec(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(4))
	{
		keycode[0] = 27;
		keycode[1] = 91;
		keycode[2] = 65;
		keycode[3] = 0;
	}
	return (keycode);
}

char	*init_next(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(4))
	{
		keycode[0] = 27;
		keycode[1] = 91;
		keycode[2] = 66;
		keycode[3] = 0;
	}
	return (keycode);
}

char	*init_left(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(4))
	{
		keycode[0] = 27;
		keycode[1] = 91;
		keycode[2] = 68;
		keycode[3] = 0;
	}
	return (keycode);
}

char	*init_right(void)
{
	char	*keycode;

	if (keycode = (char*)malloc(4))
	{
		keycode[0] = 27;
		keycode[1] = 91;
		keycode[2] = 67;
		keycode[3] = 0;
	}
	return (keycode);
}

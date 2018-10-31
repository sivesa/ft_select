SRC	= main.c \
	  list_linked.c \
	  utils.c \
	  mod_term.c \
	  print_list.c \
	  cmd.c \
	  disp_select.c \
	  move.c \
	  init_keys.c \
	  op.c \
	  init_others_keys.c \
	  list_func.c \
	  clear.c \
	  manage_cols.c \
	  signal.c \
	  ft_puts.c

NAME	= ft_select

CFLAGS	= -lncurses

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

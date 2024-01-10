CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAME	= pipex

SRCS	= pipex.c \
	utilspipex.c

all:		$(NAME)

$(NAME):
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) -I include libft/libft.a -o $(NAME)

clean:
	make clean -C libft
fclean:		clean
			make fclean -C libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

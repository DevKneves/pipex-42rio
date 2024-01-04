CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAME	= libftpipex.a

SRCS	= pipex.c \
	utilspipex.c

MAIN = pipex.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

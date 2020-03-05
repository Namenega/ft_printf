SRCNAME	= 	ft_printf.c 		\
			ft_char.c 			\
			ft_hexa.c 			\
			ft_int.c 			\
			ft_percent.c 		\
			ft_pointer.c 		\
			ft_printf_utils.c	\
			ft_printf_utils2.c	\
			ft_string.c			\
			ft_unsignedint.c	\
			
SRCS	= ${SRCNAME}

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc
RM	= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all: 		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all bonus

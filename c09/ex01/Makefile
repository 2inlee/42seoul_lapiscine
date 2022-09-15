SOURCE = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
OBJS = ${SOURCE:.c=.o}
INCS = includes
NAME = libft.a

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

${OBJS} : ${SOURCE}
	${CC} ${CFLAGS} $< -o $@ -I ${INCS}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re

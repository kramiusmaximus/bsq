NAME = BSQ

SRCS = ./srcs/ft_parse_map1.c ./srcs/ft_parse_map2.c ./srcs/ft_utils1.c ./srcs/ft_utils2.c ./srcs/ft_utils3.c ./srcs/main.c ./srcs/ft_print_square.c

OBJS = ${SRCS:.c=.o}

INCLUDE = header

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDE}

all:		${NAME}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:		
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

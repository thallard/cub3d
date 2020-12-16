SRCS =	cub3d.c \
		srcs/ft_utils.c

OBJBONUS = ${SRCBONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

HEADER = mlx.h libft.h

NAME = cub3d

CC = clang 

MINILIBX = libmlx.dylib

RM = rm -f

FLAGS = -Wall -Wextra -Werror -L. -lmlx -lft

%.o: %.c	${HEADER}
			${CC} -c  $< -o ${<:.c=.o} 

$(NAME):	${OBJS}
			${CC} $(FLAGS) -o ${NAME} ${OBJS} 

$(MINILIBX):
		@make -c minilibx/
		@cp minilibx/$(MINILIBX)

all:		${NAME}

bonus:
			${NAME}
clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
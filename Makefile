SRCS =	main.c \
		srcs/ft_utils.c \
		srcs/ft_free_all.c \
		srcs/ft_movements.c \
		srcs/ft_parser_main.c \
		srcs/ft_parser_utils.c \
		srcs/ft_raycasting_calcul.c \
		srcs/ft_render_sprites.c \
		srcs/ft_setters_struct.c \
		srcs/ft_parser_map.c \
		srcs/ft_bmp.c

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

$(MINILIBX):
		@make -C minilibx/
		@cp minilibx/$(MINILIBX) .

$(NAME):	${OBJS}
			${CC} $(FLAGS) -o ${NAME} ${OBJS} 

all:		$(MINILIBX) $(NAME)

bonus:		$(MINILIBX) ${NAME}

clean:
			${RM} ${OBJS} libmlx.dylib

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
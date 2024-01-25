NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
SRC = so_long.c end_game.c free_all.c game_init.c handle_input.c \
		map_init.c render_map.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c check_map.c enemy.c time.c \
		check_map2.c check_map3.c check_map4.c

OBJ = ${SRC:.c=.o}
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm
INCLUDES = -I mlx
LIBFT_DIR = libft
LIBFT_PATH = libft/libft.a
MLX_PATH = mlx/libmlx.a

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT_PATH} ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT_PATH} ${MLX_PATH} ${MLX_FLAGS} -o ${NAME}  

${LIBFT_PATH}:
				${MAKE} -C ${LIBFT_DIR}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
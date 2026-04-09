NAME = cub3D

SRCS =	src/main.c \
		src/data_init.c \
		src/parsing/rgb_getter.c \
		src/parsing/flood_fill.c \
		src/parsing/map_checker.c \
		src/parsing/ft_spaceslit.c \
		src/parsing/parsing_utils.c \
		src/parsing/texture_getter.c \
		src/parsing/map_and_file_getter.c \
		src/parsing/parsing.c \
		src/raycasting/wall_display.c \
		src/raycasting/DDA.c \
		src/raycasting/img_manipulation.c \
		src/raycasting/set_structs.c \
		src/game_core/handle_input.c \
		src/game_core/movement.c

OBJS = $(SRCS:.c=.o)
MLX = ./mlx_linux/libmlx.a
LIBFT = ./src/.libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux
LDFLAGS = -Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(MLX):
	make -C ./mlx_linux

$(LIBFT):
	make -C ./src/.libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C ./mlx_linux
	make clean -C ./src/.libft

fclean: clean
	$(RM) $(NAME)
	make clean -C ./mlx_linux
	make fclean -C ./src/.libft

re: fclean all

.PHONY: all clean fclean re

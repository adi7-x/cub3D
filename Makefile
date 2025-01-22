CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS = main.c src/init/init_data.c src/init/init_textures.c \
	src/parsing/parse_colors.c src/parsing/parse_file.c src/parsing/parse_map.c \
	src/parsing/parse_textures.c src/parsing/validation.c src/utils/cleanup.c \
	src/game/handel_distance.c src/game/handel_image.c \
	src/game/handel_moves.c src/game/handel_pixels.c \
	src/game/handel_tex.c get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c src/parsing/copy_map.c

OBJS = $(SRCS:.c=.o)

NAME = cub3D

INCLUDES = -I. -Ilibft

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

MLXFLAGS = -lmlx -lXext -lX11 -lm


all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

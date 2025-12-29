#Variables
NAME		= fdf
LIBFT		= libft/libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude	-Ilibft/include -I$(MLX_PATH)
RM			= rm -f

#MLX
MLX_PATH	= mlx_linux
MLX_NAME	= $(MLX_PATH)/libmlx.a
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

#SRC
SRC	= src/main.c \
	src/parsing/fill_map.c \
	src/parsing/parsing_utils.c \
	src/parsing/read_map.c \
	src/parsing/validate_input.c \
	src/graphics/bresenham.c \
	src/graphics/draw.c \
	src/graphics/init.c \
	src/graphics/hooks.c \

OBJ	= $(SRC:.c=.o)

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(INCLUDES) -Llibft -lft -o $(NAME)

%.o: %.c include/fdf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MLX_NAME):
	$(MAKE) -C $(MLX_PATH)

#test
TEST_NAME		= test_runner
TEST_SRC		= ../testing/test.c \
	src/parsing/parsing_utils.c \
	src/parsing/read_map.c \
	src/parsing/validate_input.c
TEST_OBJ		= $(TEST_SRC:.c=.o)

test: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(LIBFT) $(MLX_NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(MLX_FLAGS) $(INCLUDES) -Llibft -lft -o $(TEST_NAME)

tclean:
	$(RM) $(TEST_OBJ)
	$(RM) $(TEST_NAME)
	$(MAKE) -C libft fclean

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
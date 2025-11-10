#Variables
NAME		= fdf
LIBFT		= libft/libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude	-Ilibft/include
RM			= rm -f

#SRC
SRC	= src/main.c \
	src/parsing/validate_input.c

OBJ	= $(SRC:.c=.o)

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -Llibft -lft -o $(NAME)

%.o: %.c include/fdf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

#test
TEST			= test
TEST_SRC		= ../testing/test.c \
	src/parsing/validate_input.c
TEST_OBJ		= $(TEST_SRC:.c=.o)

test: $(TEST)

$(TEST): $(TEST_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(INCLUDES) -Llibft -lft -o $(TEST)

tclean:
	$(RM) $(TEST_OBJ)
	$(RM) $(TEST)
	$(MAKE) -C libft fclean

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
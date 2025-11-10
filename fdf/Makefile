#Variables
NAME		= fdf
LIBFT		= libft/libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude	-Ilibft/include
RM			= rm -f

#SRC
SRC	= src/main.c

OBJ	= $(SRC:.c=.o)

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -Llibft -lft -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT)
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
#Variables
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar crs
RM			= rm -f
SRC_DIR		= src
INC_DIR		= include
BONUS_DIR	= src/bonus
GNL_DIR		= src/gnl
PNTF_DIR	= src/ft_printf
ALL_OBJS 	= $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(PNTF_OBJS)

# Colors
RESET   = \033[0m
GREEN   = \033[1;32m
RED     = \033[1;31m
YELLOW  = \033[1;33m

#VPATH
VPATH = $(SRC_DIR):$(BONUS_DIR):$(GNL_DIR):$(PNTF_DIR)

#Sources
SRC_IS		= ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c
SRC_TO		= ft_toupper.c \
	ft_tolower.c
SRC_STR		= ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_substr.c \
	ft_split.c
SRC_MEM		= ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c
SRC_PUT		= ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c
SRC_CONV	= ft_atoi.c \
	ft_itoa.c
SRCS		= $(SRC_IS) $(SRC_TO) $(SRC_STR) $(SRC_MEM) $(SRC_PUT) $(SRC_CONV)
OBJS		= $(SRCS:.c=.o)

#Bonus
BONUS_SRCS	= ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

#GNL
GNL_SRCS	= ft_get_next_line_bonus.c \
	ft_get_next_line_utils_bonus.c
GNL_OBJS	= $(GNL_SRCS:.c=.o)

#PNTF
PNTF_SRCS	= ft_format_converter_pntf.c \
	ft_input_handler_pntf.c \
	ft_printer_pntf.c \
	ft_printf.c
PNTF_OBJS	= $(PNTF_SRCS:.c=.o)

#Rules
all: $(NAME)

$(NAME): $(ALL_OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)✅ libft.a $(RESET) built successfully."

%.o: %.c $(INC_DIR)/libft.h
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(RM) $(ALL_OBJS)
	@echo "$(RED)❌ All object files removed. $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)❌ libft.a executable removed. $(RESET)"

re: fclean all

.PHONY: all clean fclean re
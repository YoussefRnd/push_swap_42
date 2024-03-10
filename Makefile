NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MK = mkdir -p

LIBFT_DIR = ./lib/Libft

SRC = ./src
OBJ_DIR = ./obj
INCLUDE = ./include

HEADER = $(INCLUDE)/push_swap.h

SRCS = $(SRC)/main.c \
	$(SRC)/check_syntax.c \
	$(SRC)/stack_init.c \
	$(SRC)/stack_utils.c \
	$(SRC)/utils.c \
	$(SRC)/push.c \
	$(SRC)/swap.c \
	$(SRC)/rotate.c \
	$(SRC)/reverse_rotate.c \
	$(SRC)/sort_three.c \
	$(SRC)/sort.c

OBJS = $(SRCS:$(SRC)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC)/%.c $(HEADER)
	@$(MK) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@$(MK) $(OBJ_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

clean:	
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
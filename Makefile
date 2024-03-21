NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MK = mkdir -p

LIBFT_DIR = ./lib/Libft

SRC = ./src
SRC_BONUS = ./src/bonus
OBJ_DIR = ./obj
INCLUDE = ./include

HEADER = $(INCLUDE)/push_swap.h

SRCS = $(SRC)/main.c \
	$(SRC)/check_syntax.c \
	$(SRC)/stack_init.c \
	$(SRC)/stack_utils.c \
	$(SRC)/stack_utils2.c \
	$(SRC)/utils.c \
	$(SRC)/push.c \
	$(SRC)/swap.c \
	$(SRC)/rotate.c \
	$(SRC)/reverse_rotate.c \
	$(SRC)/sort_basic.c \
	$(SRC)/sort.c \
	$(SRC)/set_index.c \
	$(SRC)/quickSort.c \
	$(SRC)/free.c \

SRCS_BONUS = $(SRC_BONUS)/checker.c \
	lib/get_next_line_42/get_next_line.c \

SRCS_COMMON = $(SRC)/check_syntax.c \
	$(SRC)/stack_init.c \
	$(SRC)/stack_utils.c \
	$(SRC)/stack_utils2.c \
	$(SRC)/utils.c \
	$(SRC)/push.c \
	$(SRC)/swap.c \
	$(SRC)/rotate.c \
	$(SRC)/reverse_rotate.c \
	$(SRC)/sort_basic.c \
	$(SRC)/sort.c \
	$(SRC)/set_index.c \
	$(SRC)/quickSort.c \
	$(SRC)/free.c \

OBJS = $(SRCS:$(SRC)/%.c=$(OBJ_DIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS)/%.c=$(OBJ_DIR)/%.o)

IN_COMMON = $(SRCS_COMMON:$(SRC)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC)/%.c $(HEADER)
	@$(MK) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS)/%.c $(HEADER)
	@$(MK) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@echo "Making in $(LIBFT_DIR)..."
	@make -s -C $(LIBFT_DIR)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft
	@echo "$(NAME) compiled successfully!"

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(IN_COMMON) $(HEADER)
	@echo "Making in $(LIBFT_DIR)..."
	@make -s -C $(LIBFT_DIR)
	@echo "Compiling $(BONUS)..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -o $(BONUS) $(OBJS_BONUS) $(IN_COMMON) -L $(LIBFT_DIR) -lft
	@echo "$(BONUS) compiled successfully!"

clean:	
	@echo "Cleaning objects..."
	@$(RM) $(OBJS)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@$(RM) $(NAME)
	@make -s fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MK = mkdir -p

LIBFT_DIR = ./lib/Libft

SRC_MANDATORY = ./src/mandatory
SRC_BONUS = ./src/bonus
OBJ_DIR = ./obj
INCLUDE = ./include

HEADER = $(INCLUDE)/push_swap.h

SRCS = $(SRC_MANDATORY)/main.c \
	$(SRC_MANDATORY)/check_syntax.c \
	$(SRC_MANDATORY)/stack_init.c \
	$(SRC_MANDATORY)/stack_utils.c \
	$(SRC_MANDATORY)/stack_utils2.c \
	$(SRC_MANDATORY)/utils.c \
	$(SRC_MANDATORY)/push.c \
	$(SRC_MANDATORY)/swap.c \
	$(SRC_MANDATORY)/rotate.c \
	$(SRC_MANDATORY)/reverse_rotate.c \
	$(SRC_MANDATORY)/sort_basic.c \
	$(SRC_MANDATORY)/sort.c \
	$(SRC_MANDATORY)/set_index.c \
	$(SRC_MANDATORY)/quickSort.c \
	$(SRC_MANDATORY)/free.c \

OBJS = $(SRCS:$(SRC_MANDATORY)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS = $(SRC_BONUS)/checker_bonus.c \
	$(SRC_BONUS)/check_syntax_bonus.c \
	$(SRC_BONUS)/stack_init_bonus.c \
	$(SRC_BONUS)/stack_utils_bonus.c \
	$(SRC_BONUS)/stack_utils2_bonus.c \
	$(SRC_BONUS)/utils_bonus.c \
	$(SRC_BONUS)/free_bonus.c \
	$(SRC_BONUS)/get_next_line_bonus.c \
	$(SRC_BONUS)/get_next_line_utils_bonus.c \
	$(SRC_BONUS)/push_bonus.c \
	$(SRC_BONUS)/swap_bonus.c \
	$(SRC_BONUS)/rotate_bonus.c \
	$(SRC_BONUS)/reverse_rotate_bonus.c \

OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_MANDATORY)/%.c $(HEADER)
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

$(OBJ_DIR)/%.o: $(SRC_BONUS)/%.c $(HEADER)
	@$(MK) $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(BONUS): $(OBJS_BONUS) $(HEADER)
	@echo "Making in $(LIBFT_DIR)..."
	@make -s -C $(LIBFT_DIR)
	@echo "Compiling $(BONUS)..."
	@$(CC) $(CFLAGS) -I $(INCLUDE) -o $(BONUS) $(OBJS_BONUS) -L $(LIBFT_DIR) -lft
	@echo "$(BONUS) compiled successfully!"

clean:	
	@echo "Cleaning objects..."
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@echo "Cleaning executable..."
	@$(RM) $(NAME) $(BONUS)
	@make -s fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
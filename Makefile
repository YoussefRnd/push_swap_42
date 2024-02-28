NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MK = mkdir -p

LIBFT_DIR = ./lib/libft

SRC = ./src
OBJ_DIR = ./obj
INCLUDE = ./include

HEADER = $(INCLUDE)/push_swap.h

SRCS = $(SRC)/main.c \

OBJS = $(SRCS:$(SRC)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)


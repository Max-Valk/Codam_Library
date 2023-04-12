# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/09 14:04:26 by mvalk         #+#    #+#                  #
#    Updated: 2023/04/06 15:28:18 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Variable definitions

NAME := push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = inc/push_swap.h
OBJ_DIR = obj
SRCFILES = 	main.c \
			input_checks.c \
			sorting_test.c \
			small_sort.c \
			sort_20.c \
			sort_100.c \
			sort_500.c \
			sort_big.c \
			quicksort_array.c \
			stack_building.c \
			stack_management.c \
			pushes.c \
			swaps.c \
			rotate.c \
			reverse_rotate.c

vpath %.c	src stack
OBJFILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCFILES))

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

all: $(NAME)

$(NAME): $(OBJFILES) $(HEADER)
	@cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJFILES) libft/libft.a -o $(NAME)
	@echo "$(GREEN)compilation complete!$(COLOR_END)"

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJFILES) $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ./libft
	@echo "$(CYAN)clean complete!$(COLOR_END)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re bonus

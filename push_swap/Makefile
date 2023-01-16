# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/09 14:04:26 by mvalk         #+#    #+#                  #
#    Updated: 2023/01/16 15:05:27 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Variable definitions

NAME := push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = ft_printf.h
OBJ_DIR = obj
SRCFILES = 	stack_building.c \
			pushes.c \
			swaps.c \
			rotate.c \
			reverse_rotate.c \
			main.c \
		
OBJFILES = $(SRCFILES:%.c=$(OBJ_DIR)/%.o)

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	@cd libft && $(MAKE)
	@cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJFILES)
	@echo "$(GREEN)compilation complete!$(COLOR_END)"
	
$(OBJ_DIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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

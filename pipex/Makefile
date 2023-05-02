# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/09 14:04:26 by mvalk         #+#    #+#                  #
#    Updated: 2023/05/02 12:02:50 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Variable definitions

NAME := pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = inc/pipex.h
OBJ_DIR = obj
SRCFILES = 	main.c \
			pipex.c \
			utils.c \
			
			
vpath %.c	src
OBJFILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCFILES))

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

all: $(NAME)

$(NAME): $(OBJFILES) $(HEADER)
	@$(MAKE) -C libft
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

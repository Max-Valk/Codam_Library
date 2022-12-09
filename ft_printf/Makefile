# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2022/12/07 15:18:07 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Variable definitions

NAME := libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = ft_printf.h
OBJ_DIR = obj
SRCFILES = 	ft_printf_utils.c \
			ft_printf.c \
		
OBJFILES = $(SRCFILES:%.c=$(OBJ_DIR)/%.o)

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	@cd libft && $(MAKE) bonus
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

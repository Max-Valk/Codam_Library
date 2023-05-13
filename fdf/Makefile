# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2023/05/13 15:19:35 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fakedef
CC = gcc -g
# CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLX_INC = MLX42/build/libmlx42.a -I MLX42/include/MLX42 -lglfw3
HEADERFILES = fdf.h
OBJ_DIR = obj
SRCFILES = 	main.c \
			convert_file.c \
			fdf_mlx_init.c \
			rotate_points.c \
			

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

vpath %.c
OBJFILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCFILES))
		
all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	@$(MAKE) -C ./libft
	$(CC) $(OBJFILES) libft/libft.a -o $(NAME) $(MLX_FLAGS) $(MLX_INC)

$(OBJ_DIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) $(MLX_FLAGS) $(MLX_INC) -c $< -o $@

clean:
	@rm -f $(OBJFILES)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ./libft
	@echo "$(CYAN)clean complete!$(COLOR_END)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re bonus

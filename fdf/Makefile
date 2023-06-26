# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2023/06/26 19:19:24 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
MLX42 = MLX42
MLX_LIB = $(MLX42)/build/libmlx42.a
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit $(MLX_LIB) -Iinclude -lglfw3
HEADERFILES = fdf.h
OBJ_DIR = obj
SRCFILES = 	main.c \
			file_utils.c \
			input_checks.c \
			init_fdf.c \
			key_moves.c \
			rotate_points.c \
			fdf_utils.c \
			generate_image.c \
			image_utils.c \
# Color definitions

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
COLOR_END = \033[0m

vpath %.c src
OBJFILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCFILES))
		
all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJFILES) $(HEADERFILES)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJFILES) libft/libft.a -o $(NAME) $(MLX_FLAGS)  -I $(MLX42)/include/MLX42
	@echo "$(GREEN)compilation complete!$(COLOR_END)"

$(OBJ_DIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(MLX42)/include/MLX42
	@echo "$(BLUE)compiling $< $(COLOR_END)"

$(MLX_LIB):
	@git submodule init
	@git submodule update
	@cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4

clean:
	@rm -f $(OBJFILES)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX42)/build
	@echo "$(CYAN)clean complete!$(COLOR_END)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re bonus

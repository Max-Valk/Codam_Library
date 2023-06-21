# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2023/06/21 14:37:50 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -g
CFLAGS = -Wall -Wextra #-fsanitize=address
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -LMLX42/build -lmlx42 -Iinclude -lglfw3
HEADERFILES = fdf.h
OBJ_DIR = obj
SRCFILES = 	main.c \
			file_utils.c \
			input_checks.c \
			mlx_init.c \
			key_moves.c \
			rotate_points.c \
			fdf_utils.c \
			generate_image.c \
			image_utils.c \
# fdf_mlx_init.c
			

# Color definitions

GREEN = \033[0;92m
CYAN = \033[0;96m
COLOR_END = \033[0m

vpath %.c src
OBJFILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCFILES))
		
all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	@$(MAKE) -C ./libft
	$(CC) $(OBJFILES) libft/libft.a -o $(NAME) $(MLX_FLAGS)  -I MLX42/include/MLX42

$(OBJ_DIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I MLX42/include/MLX42 
#$(MLX_FLAGS)

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

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2022/11/03 16:37:24 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBRARY = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = ft_printf.h libft/libft.h
SRCFILES = ft_print_write_utils.c \
			ft_printf.c \

# SRC_BONUS = 

		
OBJFILES = $(SRCFILES:%.c=obj/%.o)

# OBJ_BONUS = $(SRC_BONUS:%.c=obj/%.o)
		
all: $(NAME)

$(NAME): $(OBJFILES)
	ar -crs $(NAME) $(OBJFILES)
	cd $(LIBRARY) && make

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	ar -crs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJFILES) $(OBJ_BONUS)
	cd $(LIBRARY) && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus

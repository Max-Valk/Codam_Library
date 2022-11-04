# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2022/11/04 17:03:32 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = ft_printf.h
SRCFILES = ft_printf_pxX.c \
		ft_printf_siu.c \
		ft_printf.c \

# SRC_BONUS = 

		
OBJFILES = $(SRCFILES:%.c=obj/%.o)

# OBJ_BONUS = $(SRC_BONUS:%.c=obj/%.o)
		
all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	@ar -crs $(NAME) $(OBJFILES)
	

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(OBJ_BONUS)
# 	ar -crs $(NAME) $(OBJ_BONUS)

clean:
	@rm -f $(OBJFILES) $(OBJ_BONUS)
	@make clean ./libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re bonus

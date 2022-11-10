# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2022/11/04 17:28:28 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC = gcc
MAKE = make
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = ft_printf.h
SRCFILES = ft_printf_pxX.c \
		ft_printf_siu.c \
		ft_printf.c \
		
OBJFILES = $(SRCFILES:%.c=obj/%.o)
		
all: $(NAME)

$(NAME): $(OBJFILES) $(HEADERFILES)
	ar -crs $(NAME) $(OBJFILES)
	@cd libft && $(MAKE) bonus
	@cp libft/libft.a $(NAME)
	
obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJFILES) $(OBJ_BONUS)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 17:23:55 by mvalk         #+#    #+#                  #
#    Updated: 2022/10/28 17:24:21 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := 
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = .h
SRCFILES = 

		
SRC_BONUS = 

		
OBJFILES = $(SRCFILES:%.c=obj/%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=obj/%.o)
		
all: $(NAME)

$(NAME): $(OBJFILES)
	ar -crs $(NAME) $(OBJFILES)

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	ar -crs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJFILES) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus

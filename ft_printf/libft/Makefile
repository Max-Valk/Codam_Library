# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 17:16:34 by mvalk         #+#    #+#                  #
#    Updated: 2022/11/04 17:28:53 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = libft.h
SRCFILES = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c \

		
SRC_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJFILES = $(SRCFILES:%.c=obj/%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -crs $(NAME) $(OBJFILES)

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) $(OBJFILES)
	@ar -crs $(NAME) $(OBJ_BONUS) $(OBJFILES)

clean:
	@rm -f $(OBJFILES) $(OBJ_BONUS)
	@rm -r -f obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus

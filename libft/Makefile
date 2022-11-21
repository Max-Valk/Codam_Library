# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvalk <mvalk@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 17:16:34 by mvalk         #+#    #+#                  #
#    Updated: 2022/11/18 13:39:15 by mvalk         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERFILES = libft.h
OBJ_DIR = obj

# Colors

RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
COLOR_END = \033[0m

# Sources

SRCFILES := ft_atoi.c \
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

		
SRC_BONUS := ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJFILES = $(SRCFILES:%.c=$(OBJ_DIR)/%.o)

OBJ_BONUS := $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -crs $(NAME) $(OBJFILES)
	@echo "$(GREEN)compilation complete!$(COLOR_END)"

$(OBJ_DIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)compiling $< $(COLOR_END)"

bonus: $(OBJ_BONUS)
	@ar -crs $(NAME) $(OBJ_BONUS) $(OBJFILES)

clean:
	@rm -f $(OBJFILES) $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)clean complete!$(COLOR_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)fclean complete!$(COLOR_END)"

re: fclean all
	@echo "$(RED)fclean and recompile complete!$(COLOR_END)"

.PHONY: clean all fclean re bonus

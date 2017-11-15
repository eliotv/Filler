# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 16:44:34 by evanheum          #+#    #+#              #
#    Updated: 2017/11/14 15:35:43 by evanheum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes -I libft/includes
LDFLAGS += -L libft/ -lft

LIBFT := libft/libft.a

FILLERDR = 	\
	filler.c \
	readfile.c \
	heatmap.c \
	init.c \
	trim_piece.c \
	store.c \
	place.c \

SRC = $(addprefix src/, $(FILLERDR))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[31m -- Object Files Removed --\033[0m"

fclean:
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[31m   -- libftfiller.a Removed --\033[0m"

re: fclean all

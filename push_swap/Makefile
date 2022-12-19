# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 10:17:46 by ecamara           #+#    #+#              #
#    Updated: 2022/02/02 11:20:03 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = push_swap.c

FLG = -Wall -Werror -Wextra -g3 -fsanitize=address
CC = gcc

SRCO = $(.c=.o)
LIB = libft/libft.a
INCLUDES = push_swap.h
all: $(NAME)

$(LIB) : libft/*.c
	make -C libft
	make -C libft/ bonus
$(NAME): $(SRC) $(LIB)
	$(CC) $(FLG) $(LIB) $< -o $(NAME)
clean:
	rm -f $(SRCO)
	make -C libft/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
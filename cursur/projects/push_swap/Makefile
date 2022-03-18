# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 10:17:46 by ecamara           #+#    #+#              #
#    Updated: 2022/03/11 14:02:09 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC =	source/push_swap.c	\
		source/aux.c		\
		source/commands.c	\
		source/commands2.c	\
		source/commands3.c	\
		source/error_free.c	\
		source/input.c		\
		source/logic.c		\
		source/logic2.c	

SRCO = $(.c=.o)
FLG = -Wall -Werror -Wextra #-g3 -fsanitize=address
CC = gcc

LIB = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLG) -c $^ -o $@

$(LIB) : libft/*.c
	make -C libft
	make -C libft/ bonus
$(NAME): $(SRC) $(LIB)
	$(CC) $(FLG) $(LIB) $^ -o $(NAME)

clean:
	rm -f $(SRCO)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
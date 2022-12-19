# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:31:04 by ecamara           #+#    #+#              #
#    Updated: 2022/09/05 12:39:49 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRC =	Fixed.cpp	\
		main.cpp

INCLUDE =	Fixed.hpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLG = -Werror -Wextra -Wall

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLG) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLG) $(OBJ) -I. -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re 
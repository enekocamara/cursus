# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:31:04 by ecamara           #+#    #+#              #
#    Updated: 2022/11/22 10:09:22 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRC =	Animal.cpp	\
		Cat.cpp		\
		WrongAnimal.cpp	\
		WrongCat.cpp		\
		Dog.cpp		\
		main.cpp

INCLUDE =	Animal.hpp	\
			Cat.hpp		\
			WrongAnimal.hpp	\
			WrongCat.hpp		\
			Dog.hpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLG = -Werror -Wextra -Wall -g3

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
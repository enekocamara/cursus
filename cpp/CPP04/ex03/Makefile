# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:31:04 by ecamara           #+#    #+#              #
#    Updated: 2022/09/19 10:14:59 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Magic

SRC =	AMateria.cpp	\
		Ice.cpp			\
		Cure.cpp		\
		ICharacter.cpp	\
		Character.cpp	\
		main.cpp		\
		MateriaSource.cpp\
		IMateriaSource.cpp

INCLUDE =	AMateria.hpp	\
			Ice.hpp			\
			Cure.hpp		\
			ICharacter.hpp	\
			Character.hpp	\
			MateriaSource.hpp\
			IMateriaSource.hpp\

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLG = -Werror -Wextra -Wall

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLG) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLG) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re 
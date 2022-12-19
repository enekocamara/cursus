# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:31:04 by ecamara           #+#    #+#              #
#    Updated: 2022/06/20 11:06:36 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = humans

SRC =	HumanA.cpp	\
		HumanB.cpp	\
		Weapon.cpp	\
		main.cpp

INCLUDE =	HumanA.hpp	\
			HumanB.hpp	\
			Weapon.hpp

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
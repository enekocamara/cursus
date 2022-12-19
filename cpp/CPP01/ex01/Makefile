# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 10:50:31 by ecamara           #+#    #+#              #
#    Updated: 2022/06/20 10:13:20 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC =	main.cpp		\
		Zombie.cpp		\
		ZombieHorde.cpp

INCLUDES = Zombie.hpp

FLAGS = -Werror -Wextra -Wall

CC = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
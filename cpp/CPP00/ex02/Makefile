# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:41:59 by ecamara           #+#    #+#              #
#    Updated: 2022/06/17 10:15:27 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = accounts

SRC = 	Account.cpp	\
		tests.cpp

INCLUDES = Account.hpp

FLAGS = -Werror -Wextra -Wall

CC = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
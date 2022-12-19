# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:31:04 by ecamara           #+#    #+#              #
#    Updated: 2022/12/12 14:58:56 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRC =	Bureaucrat.cpp	\
		main.cpp		\
		Form.cpp		\

INCLUDE =	color.h			\
			Bureaucrat.hpp	\
			Form.hpp		\

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
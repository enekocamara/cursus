# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:49:28 by ecamara           #+#    #+#              #
#    Updated: 2022/03/28 10:33:25 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Contact_list

SRC = 	main.cpp			\
		Contact_list.cpp	\
		Contact.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = 	Contact_list.hpp	\
			contact.hpp

FLAGS =  -Werror -Wextra -Wall

CC = clang++

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDE)
		$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

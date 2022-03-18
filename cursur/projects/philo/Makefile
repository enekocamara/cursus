# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 11:21:52 by ecamara           #+#    #+#              #
#    Updated: 2022/03/15 10:53:48 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	source/philo.c		\
		source/aux.c		\
		source/death.c		\
		source/error.c		\
		source/input.c		\
		source/philo.c		\
		source/process.c	\
		source/time.c		\
		source/utils.c		

SRCO = $(.c=.o)

CC = gcc
RM = rm -rf
FLG = -Wall -Wextra -Werror -pthread

all: $(NAME)

%.o: %.c
	$(CC) $(FLG) -c $^ -o $@

$(NAME): $(SRC)
	@$(CC) $(FLG) $(SRCO) $^ -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
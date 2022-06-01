# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 11:21:52 by ecamara           #+#    #+#              #
#    Updated: 2022/05/05 09:26:53 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	src/philo.c		\
		src/aux.c		\
		src/error.c		\
		src/group.c		\
		src/philo.c		\
		src/process.c	\
		src/time.c		\
		src/utils.c		

SRCO = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
FLG = -Wall -Wextra -Werror -pthread #-fsanitize=address -g3

all: $(NAME)

%.o: %.c
	$(CC) $(FLG) -c $^ -o $@

$(NAME): $(SRCO)
	@$(CC) $(FLG) $^ -o $@

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
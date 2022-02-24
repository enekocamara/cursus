# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 10:17:46 by ecamara           #+#    #+#              #
#    Updated: 2022/01/18 10:12:10 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME2 = server
NAME_BONUS = client_b
NAME2_BONUS = server_b

SRC = client.c	
SRCO = $(SRC:.c=.o)
SRC2 = server.c
SRCO2 = $(SRC2:.c=.o)

SRC_BONUS = client_bonus.c
SRCO_BONUS = $(SRC_BONUS:.c=.o)
SRC2_BONUS = server_bonus.c
SRCO2_BONUS = $(SRC2_BONUS:.c=.o)

FLG = -Wall -Werror -Wextra
CC = cc

LIB = libft/libft.a

all: $(NAME) $(NAME2)

bonus: $(NAME_BONUS) $(NAME2_BONUS)

$(NAME): $(SRC) $(LIB)
	$(CC) $(FLG) $(LIB) $< -o $(NAME)
	
$(NAME2): $(SRC2) $(LIB)
	$(CC) $(FLG) $(LIB) $< -o $(NAME2)

$(NAME_BONUS): $(SRC_BONUS) $(LIB)
	$(CC) $(FLG) $(LIB) $< -o $(NAME_BONUS)
	
$(NAME2_BONUS): $(SRC2_BONUS) $(LIB)
	$(CC) $(FLG) $(LIB) $< -o $(NAME2_BONUS)

$(LIB) : libft/*.c libft/*.h 
	make -C libft

clean:
	rm -f $(SRCO) $(SRCO2) $(SRCO_BONUS) $(SRCO2_BONUS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME_BONUS) $(NAME2_BONUS)

re: fclean all

.PHONY: all clean fclean re
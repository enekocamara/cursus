# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 11:09:43 by ecamara           #+#    #+#              #
#    Updated: 2022/01/18 12:40:36 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC =	sources/so_long.c	\
		sources/display.c	\
		sources/display2.c	\
		sources/display3.c	\
		sources/display4.c	\
		sources/extra.c 	\
		sources/extra2.c 	\
		sources/imput.c		\
		sources/events.c	\
		sources/error.c		\
		sources/error2.c

SRC_BONUS = sources_bonus/so_long.c	\
		sources_bonus/display.c		\
		sources_bonus/display2.c	\
		sources_bonus/display3.c	\
		sources_bonus/display4.c	\
		sources_bonus/extra.c 		\
		sources_bonus/extra2.c 		\
		sources_bonus/imput.c		\
		sources_bonus/events.c		\
		sources_bonus/error.c		\
		sources_bonus/error2.c

SRCO = $(SRC:.c=.o)
SRCO_BONUS = $(SRC_BONUS:.c=.o)

FLG = -Wall -Werror -Wextra -g 
CC = gcc

LIB = libft/libft.a
MLX = mlx/libmlx.a

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(SRCO) $(LIB) $(MLX)
	$(CC) $(FLG) $(LIB) -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(NAME_BONUS): $(SRCO_BONUS) $(LIB) $(MLX)
	$(CC) $(FLG) $(LIB) -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(LIB):
	make -C libft

$(MLX) :
	make -C mlx

clean:
	make -C libft/ clean
	make -C mlx/ clean
	rm -f $(SRCO) $(SRCO_BONUS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 10:27:21 by ecamara           #+#    #+#              #
#    Updated: 2021/09/20 10:57:23 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
LIB		:= ar rcs

SRC := ft_printf.c printffunctions.c
OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

%.o:	%.c libft.h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f $(OBJS)

fclean: 
	rm -f $(NAME) $(OBJS)

re: fclean all
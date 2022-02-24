# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:49:38 by cdiaz-fl          #+#    #+#              #
#    Updated: 2022/02/11 17:49:37 by ecamara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

#SRCS	= 	main.c\
FILES	= 	main.c\
			minishell_utils.c \
			aux.c\
			functions.c\

FILES	= 	main \
			minishell_utils \
			aux \
			functions \
			
#OBJS	= ${SRCS:.c=.o}
SRCS	= $(addsuffix .c ,$(FILES));
OBJS	= $(addsuffix .o ,$(FILES));

SNAME	= fsanitize

RM		= rm -rf

CC		= gcc

RED		= \033[0;31m

GREEN	= \033[0;32m

WHITE	= \033[0;37m

LIBFT 	=  -C ./libft

#LDFLAGS =	-I/sgoinfre/goinfre/Perso/$(USER)/homebrew/opt/readline/include\
			-lreadline\
			-L/sgoinfre/goinfre/Perso/$(USER)/homebrew/opt/readline/lib\

SFLAGS	= -fsanitize=address

CFLAGS	= -g3 -Wall -Werror -Wextra 

LDFLAGS	= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/ -I/Users/$(USER)/.brew/opt/readline/include/readline/

#%.o: %.c
#	$(CC) $(CFLAGS) -I/Users/$(USER)/.brew/opt/readline/include/1.1.2/readline/ -I/Users/$(USER)/.brew/opt/readline/1.8.2/lib/ -c $< -o $@ 

.c.o: $(OBJS)
	$(CC) $(CFLAGS) -I/Users/$(USER)/.brew/opt/readline/include/1.1.2/readline/ -I/Users/$(USER)/.brew/opt/readline/1.8.2/lib/ -c $< -o $@

all: $(NAME)	

$(NAME) : $(OBJS)
			 echo "$(RED)Compiling...			⏳$(WHITE)"
			 make  ${LIBFT}/
			 $(CC) ${CFLAGS} ${LDFLAGS} $^ -I. ./libft/libft.a -o $@	

clean:
		@ echo "$(RED)Clean in progress...		⏳$(WHITE)"
		@ $(RM) *.dSYM
		@ $(RM) *.o
		@ ${MAKE} clean ${LIBFT}
		@ echo "$(GREEN)Clean done			✅$(WHITE)"

fclean: 
		@ echo "$(RED)Fclean in progress...		⏳$(WHITE)"
		@ $(RM) *.dSYM
		@ $(RM) %.o
		@ $(RM) $(NAME)
		@ ${MAKE} fclean ${LIBFT}
		@ echo "$(GREEN)Fclean done			✅$(WHITE)"

re:		fclean all

.PHONY: all s clean fclean re

NAME = philo

SRC =	philo.c\

SRCO = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
FLG = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread#

all: $(NAME)
$(NAME): $(SRCO)
	@$(CC) $(FLG) $(SRCO) -o $(NAME)
$(SRCO): $(SRC)
	@$(CC) $(CFLAGS) -c $^ 
clean:
	@rm -rf $(OBJ_DIR)
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
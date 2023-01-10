NAME = Array

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES = Array.hpp

CC = clang++

FLAGS = -Werror -Wextra -Wall -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: re clean fclean all
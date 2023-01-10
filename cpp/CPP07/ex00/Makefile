NAME = Whatever

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES = whatever.hpp

CC = clang++

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean re

PHONY: re clean fclean all
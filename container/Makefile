NAME = containers

SRC =	main.cpp	\
		Vector.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = Vector.hpp

CC = clang++

FLGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(FLGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC) $(FLGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all re clean fclean
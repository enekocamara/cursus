NAME = span

SRC =	main.cpp\
		Span.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES = Span.hpp

CC = clang++

FLAGS = -Werror -Wextra -Wall -std=c++98

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
NAME = unitTester

SRC = 	mainTester.cpp	\
		Checker.cpp		\
		../convert.cpp	\
		../Void.cpp

OBJ  = $(SRC:.cpp=.o)

INCLUDES =	Checker.hpp\
			../Void.hpp

FLAGS = -Wall -Werror -Wextra

CC = clang++


all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all re clean fclean
NAME = convert

SRC = 	main.cpp	\
		Void.cpp	\
		convert.cpp	\

OBJ = $(SRC:.cpp=.o)

INCLUDES = Void.hpp

CC = clang++

FLAGS = -Werror -Wall -Werror

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

PHONY: all clean fclean re
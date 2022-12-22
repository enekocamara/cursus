NAME = convert

SRC =	main.cpp	\
		Char.cpp	\
		Int.cpp		\
		Float.cpp	\
		Double.cpp	\
		Void.cpp	\

INCLUDES =	Char.hpp	\
			Int.hpp		\
			Float.hpp	\
			Double.hpp	\
			Void.hpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLG = -Werror -Wextra -Wall 

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLG) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLG) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re 
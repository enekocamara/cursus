NAME = Serialization

SRC =	main.cpp	\
		Data.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES = 	header.h	\
			Data.hpp

FLAGS =  -Wall -Werror -Wextra

CC = clang++

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re

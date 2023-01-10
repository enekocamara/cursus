NAME = Identify

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDES =	Base.hpp	\
			A.hpp		\
			B.hpp		\
			C.hpp

FLAGS = -Werror -Wextra -Wall

CC = clang++

all: $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re
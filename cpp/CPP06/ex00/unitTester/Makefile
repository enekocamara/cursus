NAME = unitTester

SRC =	mainTester.cpp	\
		Checker.cpp		\
		../Char.cpp		\
		../Int.cpp		\
		../Float.cpp	\
		../Double.cpp	\
		../Void.cpp		\

INCLUDES =	Checker.hpp		\
			../Char.hpp		\
			../Int.hpp		\
			../Float.hpp	\
			../Double.hpp	\
			../Void.hpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

CPPFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CPPFLAGS) $(OBJ) -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: clean fclean re all
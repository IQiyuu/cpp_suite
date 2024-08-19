NAME = PmergeMe

F = main\
	PmergeMe


S = $(foreach f, $(F), srcs/$(f).cpp)
OBJ = $(S:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Iheaders -fsanitize=address -g

all: $(NAME)
r: re
	./$(NAME) 5 0 9 6 7 2

$(NAME): $(OBJ)
	c++ $(OBJ) $(CFLAGS) -o $(NAME)

.cpp.o:
	c++ -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
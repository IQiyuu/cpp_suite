NAME = bureaucrat

F = main\
	Bureaucrat\


S = $(foreach f, $(F), $(f).cpp)
OBJ = $(S:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

GREEN	= \033[32m
RED		= \033[31m
WHITE	= \033[0m

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(CFLAGS) -o $(NAME)
	@printf "\033[0m"

.cpp.o:
	@printf "\033[32m"
	c++ -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)
	@printf "$(RED)all .o deletete$(WHITE)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)$(NAME) deletete$(WHITE)\n"

re: fclean all
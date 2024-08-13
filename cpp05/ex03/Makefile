NAME = bureaucrat

F = main\
	Bureaucrat\
	AForm\
	ShrubberyCreationForm\
	RobotomyRequestForm\
	PresidentialPardonForm\
	Intern


S = $(foreach f, $(F), srcs/$(f).cpp)
OBJ = $(S:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Iheaders

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(CFLAGS) -o $(NAME)

.cpp.o:
	c++ -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
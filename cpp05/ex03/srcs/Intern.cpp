#include "Intern.hpp"

Intern::Intern( void ) {
    std::cout << "Intern \033[32mcreated\033[0m" << std::endl;
}

Intern::Intern( Intern const &ref ) {
    std::cout << "Intern copy \033[32mcreated\033[0m" << std::endl;
    (void)ref;
}

Intern::~Intern( void ) {
    std::cout << "Intern \033[31mdeleted\033[0m" << std::endl;
}

Intern &Intern::operator=( Intern const &ref ) {
    (void)ref;
    return *this;
}

static AForm	*makePresident( const std::string target ) {
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot( const std::string target ) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery( const std::string target ) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm( std::string form, std::string target ) const {
    std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(*forms[])(const std::string target) = {&makeShrubbery, &makeRobot, &makePresident};	
    for (int i = 0; i < 3; i++) {
        if (names[i] == form) {
            std::cout << names[i] << std::endl;
            std::cout << "Intern created form `" << form << "'." << std::endl;
            return (*(forms[i]))(target);
        }
    }
    std::cout << "ERROR: form `" <<  form << "' not found" << std::endl;
    return NULL;
}
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

AForm    *Intern::makeForm( std::string formName, std::string formTarget) const {
    AForm*    forms[] = {   new ShruberryCreationForm( formTarget ), 
                            new RobotomyRequestForm( formTarget ), 
                            new PresidentialPardonForm( formTarget ) };
    std::string formsName[] = { "ShruberryCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };

    for (int i = 0; i < 3; i++) {
        if (formsName[i] == formName) {
            std::cout << "Intern creates form " << formName << std::endl;
            return (forms[i]);
        }
    }
    std::cout << "form : " << formName << " does not exist" << std::endl;
    return (NULL);
}
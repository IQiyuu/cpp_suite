#ifndef INTERN
# define INTERN

#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern( void );
        Intern( Intern const & );
        ~Intern( void );
        Intern	&operator=( Intern const &);

        AForm *makeForm( std::string, std::string ) const;

};

#endif
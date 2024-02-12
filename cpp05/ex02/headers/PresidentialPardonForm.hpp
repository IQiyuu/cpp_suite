#ifndef PRES
 #define PRES

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string const _target;

    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string );
        PresidentialPardonForm( PresidentialPardonForm const & );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm	&operator=( PresidentialPardonForm const &);

        void execute( Bureaucrat const & ) const;

};

#endif

#ifndef SHRU
 #define SHRU

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    private:
        std::string const _target;

    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( std::string );
        ShrubberyCreationForm( ShrubberyCreationForm const & );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &);

        void execute( Bureaucrat const & ) const;

};

#endif

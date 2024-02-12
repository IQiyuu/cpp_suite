#ifndef SHRU
 #define SHRU

#include "AForm.hpp"

class ShruberryCreationForm: public AForm {
    private:
        std::string const _target;

    public:
        ShruberryCreationForm( void );
        ShruberryCreationForm( std::string );
        ShruberryCreationForm( ShruberryCreationForm const & );
        ~ShruberryCreationForm( void );
        ShruberryCreationForm	&operator=( ShruberryCreationForm const &);

        void execute( Bureaucrat const & ) const;

};

#endif

#ifndef ROBO
 #define ROBO

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm {
    private:
        std::string const _target;

    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string );
        RobotomyRequestForm( RobotomyRequestForm const & );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm	&operator=( RobotomyRequestForm const &);

        void execute( Bureaucrat const & ) const;

};

#endif

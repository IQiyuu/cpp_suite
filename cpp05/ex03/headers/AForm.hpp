#ifndef AFORM
# define AFORM

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string const _name;
        bool              _signed;
        int const         _execGrade;
        int const         _signGrade;

    public:
        AForm( std::string const, int, int);
        AForm( void );
        AForm( AForm const & );
        virtual ~AForm( void );
        AForm &operator=( AForm const & );

        std::string const getName( void ) const;
        int         getExecGrade( void ) const;
        int         getSignGrade( void ) const;
        bool        isSigned( void ) const;
        void        beSigned( Bureaucrat & );

        virtual void execute( Bureaucrat const & ) const = 0;

        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();
            };

        class GradeTooLowException: public std::exception {
                public:
                    const char* what() const throw();
            };

        class NotSignedException: public std::exception {
                public:
                    const char* what() const throw();
            };
};

std::ostream &operator<<( std::ostream &, AForm const & );

#endif
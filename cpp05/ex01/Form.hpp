#ifndef FORM
# define FORM

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string const _name;
        bool              _signed;
        int const         _execGrade;
        int const         _signGrade;
        Form( void );

    public:
        Form( std::string const, int, int);
        Form( Form const & );
        ~Form( void );
        Form &operator=( Form const & );

        std::string const getName( void ) const;
        int         getExecGrade( void ) const;
        int         getSignGrade( void ) const;
        bool        isSigned( void ) const;
        void        beSigned( Bureaucrat & );

        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
            };

        class GradeTooLowException: public std::exception {
                public:
                    virtual const char* what() const throw();
            };
        
        class FormAlreadySignedException: public std::exception {
                public:
                    virtual const char* what() const throw();
            };
};

std::ostream &operator<<( std::ostream &, Form const & );

#endif
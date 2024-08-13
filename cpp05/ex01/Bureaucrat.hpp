#ifndef BUREAUCRAT
# define BUREAUCRAT

#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        std::string const   _name;
        int                 _grade;
        Bureaucrat( void );

    public:
        Bureaucrat( std::string const, int );
        Bureaucrat( Bureaucrat const & );
        ~Bureaucrat( void );
        Bureaucrat &operator=( Bureaucrat const & );

        std::string const getName( void ) const;
        int               getGrade( void ) const;
        void              incrementGrade( void );
        void              decrementGrade( void );
        void              signForm( Form & );
    
    class GradeTooHighException: public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<( std::ostream &, Bureaucrat const & );

#endif
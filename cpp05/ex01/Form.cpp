#include "Form.hpp"

Form::Form( std::string const name, int const signGrade, int const execGrade): _name(name), _signed(false), _execGrade(execGrade), _signGrade(signGrade) {
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
    std::cout << "Form \033[32mcreated\033[0m" << std::endl;
}

Form::Form( Form const &ref ): _name(ref._name), _signed(ref._signed), _execGrade(ref._execGrade), _signGrade(ref._signGrade) {
    std::cout << "Form copy \033[32mcreated\033[0m" << std::endl;
}

Form::~Form( void ) {
    std::cout << "Form \033[31mdeleted\033[0m" << std::endl;
}

Form    &Form::operator=( Form const &ref ) {
    this->_signed = ref._signed;
    return *this;
}

std::string const Form::getName( void ) const {
    return this->_name;
}

int Form::getExecGrade( void ) const {
    return this->_execGrade;
}

int Form::getSignGrade( void ) const {
    return this->_signGrade;
}

bool    Form::isSigned( void ) const {
    return this->_signed;
}

void    Form::beSigned( Bureaucrat &ref ) {
    if (this->_signed)
        throw FormAlreadySignedException();
    if (ref.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

const char* Form::FormAlreadySignedException::what() const throw() {
    return "Form already signed.";
}


std::ostream    &operator<<( std::ostream &os, Form const &ref ) {
    os << "Form " << ref.getName() << ":\n\t- minimum grade to sign    : " << ref.getSignGrade() << "\n\t- minimum grade to execute : " << ref.getExecGrade() << "\n\t- the form is signed       : " << ref.isSigned();
    return os;
}
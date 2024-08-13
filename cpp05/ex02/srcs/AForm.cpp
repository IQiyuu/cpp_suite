#include "AForm.hpp"

AForm::AForm( void ): _name("a form"), _signed(false), _execGrade(1), _signGrade(150) {
    std::cout << "AForm \033[32mcreated\033[0m" << std::endl;
}

AForm::AForm( std::string const name, int const signGrade, int const execGrade): _name(name), _signed(false), _execGrade(execGrade), _signGrade(signGrade) {
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
    std::cout << "AForm \033[32mcreated\033[0m" << std::endl;
}

AForm::AForm( AForm const &ref ): _name(ref._name), _signed(ref._signed), _execGrade(ref._execGrade), _signGrade(ref._signGrade) {
    std::cout << "AForm copy \033[32mcreated\033[0m" << std::endl;
}

AForm::~AForm( void ) {
    std::cout << "AForm \033[31mdeleted\033[0m" << std::endl;
}

AForm    &AForm::operator=( AForm const &ref ) {
    this->_signed = ref._signed;
    return *this;
}

std::string const AForm::getName( void ) const {
    return this->_name;
}

int AForm::getExecGrade( void ) const {
    return this->_execGrade;
}

int AForm::getSignGrade( void ) const {
    return this->_signGrade;
}

bool    AForm::isSigned( void ) const {
    return this->_signed;
}

void    AForm::beSigned( Bureaucrat &ref ) {
    if (ref.getGrade() > this->_signGrade)
        throw GradeTooLowException();
    this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form not signed.";
}

std::ostream    &operator<<( std::ostream &os, AForm const &ref ) {
    os << "AForm " << ref.getName() << ":\n\t- minimum grade to sign    : " << ref.getSignGrade() << "\n\t- minimum grade to execute : " << ref.getExecGrade() << "\n\t- the Aform is signed       : " << ref.isSigned();
    return os;
}
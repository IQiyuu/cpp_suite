#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const name, int grade ): _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat \033[32mcreated\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &ref ): _name(ref._name) {
    std::cout << "Bureaucrat with grade " << ref._grade << " copy \033[32mcreated\033[0m" << std::endl;
    this->_grade = ref._grade;
}

Bureaucrat::~Bureaucrat( void ) {
    std::cout << "Bureaucrat \033[31mdestructed\033[0m" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &ref ) {
    this->_grade = ref._grade;
    return *this;
}

std::string const Bureaucrat::getName( void ) const {
    return this->_name;
}

int Bureaucrat::getGrade( void ) const {
    return this->_grade;
}

void    Bureaucrat::incrementGrade( void ) {
    if (this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrementGrade( void ) {
    if (this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &ref) {
    os << ref.getName() << ", bureaucrate grade: " << ref.getGrade();
    return os;
}
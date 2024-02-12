#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 145, 137), _target("") {
    std::cout << "Shrumachin \033[32mcreated\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardonForm", 145, 137), _target(target) {
    std::cout << "Shrumachin \033[32mcreated\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &ref ): AForm(ref), _target("") {
    std::cout << "Shrumachin copy \033[32mcreated\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
    std::cout << "Shrumachin \033[31mdeleted\033[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &ref ) {
    (void)ref;
    return *this;
}

void    PresidentialPardonForm::execute( const Bureaucrat& exec ) const {
     if ( this->isSigned() == false )
        throw AForm::NotSignedException();
    else if ( exec.getGrade() > this->getExecGrade() ) {
        throw AForm::GradeTooLowException();
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}

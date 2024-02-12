#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45), _target("") {
    std::cout << "Robomachin \033[32mcreated\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Robomachin \033[32mcreated\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &ref ): AForm(ref), _target("") {
    std::cout << "Robomachin copy \033[32mcreated\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "Robomachin \033[31mdeleted\033[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &ref ) {
    (void)ref;
    return *this;
}

void    RobotomyRequestForm::execute( const Bureaucrat& exec ) const {
    static int i = 0;
    if ( this->isSigned() == false )
        throw AForm::NotSignedException();
    else if ( exec.getGrade() > this->getExecGrade() ) {
        throw AForm::GradeTooLowException();
    }
    if (i % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "robotomization failed" << std::endl;
    i++;
}

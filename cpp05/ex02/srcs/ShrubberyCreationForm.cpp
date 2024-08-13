#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137), _target("") {
    std::cout << "Shrumachin \033[32mcreated\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Shrumachin \033[32mcreated\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &ref ): AForm(ref), _target("") {
    std::cout << "Shrumachin copy \033[32mcreated\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    std::cout << "Shrumachin \033[31mdeleted\033[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &ref ) {
    (void)ref;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& exec ) const {
     if ( this->isSigned() == false )
        throw AForm::NotSignedException();
    else if ( exec.getGrade() > this->getExecGrade() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream f;
    std::string name = this->_target + "_shrubbery";
    f.open( name.data() );
    f << "          &&& &&  & &&" << std::endl;
    f << "       && &\\/&\\|& ()|/ @, &&" << std::endl;
    f << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    f << "   &() &\\/&|()|/&\\/ \'%\" & ()" << std::endl;
    f <<  "&_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    f << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    f << "()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    f << "    &&     \\|||" << std::endl;
    f << "            |||" << std::endl;
    f << "            |||" << std::endl;
    f << "            |||" << std::endl;
    f << "      , -=-~  .-^- _" << std::endl;
    f.close();
}

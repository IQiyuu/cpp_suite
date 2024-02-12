#include "Intern.hpp"

int main() {
    std::cout << "\nTEST WITH GRADE 1000" << std::endl;
    try {
        Bureaucrat bu("test", 1000);
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST WITH GRADE -40" << std::endl;
    try {
        Bureaucrat bo("test", -40);
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST INCREMENT WITH GRADE 1" << std::endl;
    Bureaucrat bp("test", 1);
    std::cout << bp << std::endl;
    try {
        bp.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST DECREMENT WITH GRADE 150" << std::endl;
    Bureaucrat bl("test", 150);
    std::cout << bl << std::endl;
    try {
        bl.decrementGrade();
        std::cout << bl << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST INCREMENT WITH GRADE 10" << std::endl;
    Bureaucrat bj("test", 10);
    std::cout << bj << std::endl;
    try {
        bj.incrementGrade();
        std::cout << bj << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST DECREMENT WITH GRADE 10" << std::endl;
    Bureaucrat bi("test", 10);
    std::cout << bi << std::endl;
    try {
        bi.decrementGrade();
        std::cout << bi << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat grade not valid: " << e.what() << std::endl;
    }

    std::cout << "TEST SHRU FORM" << std::endl;
    try {
        AForm *f = new ShruberryCreationForm("home");
        bi.signForm(*f);
        f->execute(bi);
        delete f;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTEST INTERN" << std::endl;
    Intern i;
    i.makeForm("GUHEUIFHASUFHKF", "Robert");
    AForm *test = i.makeForm("PresidentialPardonForm", "Robert");
    bi.signForm(*test);
    delete test;
    return 0;
}
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\nTEST WITH GRADE 1000" << std::endl;
    try {
        Bureaucrat bu("test", 1000);
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST WITH GRADE -40" << std::endl;
    try {
        Bureaucrat bo("test", -40);
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST INCREMENT WITH GRADE 1" << std::endl;
    Bureaucrat bp("test", 1);
    std::cout << bp << std::endl;
    try {
        bp.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST DECREMENT WITH GRADE 150" << std::endl;
    Bureaucrat bl("test", 150);
    std::cout << bl << std::endl;
    try {
        bl.decrementGrade();
        std::cout << bl << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST INCREMENT WITH GRADE 10" << std::endl;
    Bureaucrat bj("test", 10);
    std::cout << bj << std::endl;
    try {
        bj.incrementGrade();
        std::cout << bj << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST DECREMENT WITH GRADE 10" << std::endl;
    Bureaucrat bi("test", 10);
    std::cout << bi << std::endl;
    try {
        bi.decrementGrade();
        std::cout << bi << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Bureaucrat not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 1 EXEC 0" << std::endl;
    try {
        Form f("test", 1, 0);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 0 EXEC 1" << std::endl;
    try {
        Form f("test", 0, 1);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 0 EXEC 151" << std::endl;
    try {
        Form f("test", 0, 151);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 151 EXEC 0" << std::endl;
    try {
        Form f("test", 151, 0);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 151 EXEC 151" << std::endl;
    try {
        Form f("test", 151, 151);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST FORM SIGN 15 EXEC 15" << std::endl;
    try {
        Form f("test", 15, 15);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST GRADE 20 SIGN FORM SIGN 15 EXEC 15" << std::endl;
    try {
        Form f("Important", 15, 15);
        Bureaucrat r("Robert", 20);
        std::cout << r << std::endl;
        std::cout << f << std::endl;
        r.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }

    std::cout << "\nTEST GRADE 1 SIGN FORM SIGN 15 EXEC 15" << std::endl;
    try {
        Form f("Important", 15, 15);
        Bureaucrat r("Robert", 1);
        std::cout << r << std::endl;
        std::cout << f << std::endl;
        r.signForm(f);
        std::cout << f << std::endl;
        r.signForm(f);
    } catch (std::exception &e) {
        std::cout << "Error: Form not valid: " << e.what() << std::endl;
    }
    return 0;
}
#include "RPN.hpp"

int main (int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "program must be launched like: ./RPN <exp>" << std::endl;
        return 0;
    }
    std::string arg = av[1];
    RPN test;
    test.calcul(arg);
    return 0;
}
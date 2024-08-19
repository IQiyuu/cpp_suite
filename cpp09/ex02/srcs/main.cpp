#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    try {
        PmergeMe p(ac, av);
        p.sortAll();
    } catch ( std::exception &e ) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base    *generate( void ) {
    int r = std::rand() % 3;
    switch (r) {
        case 0:
            std::cout << "A created." << std::endl;
            return new A();
        case 1:
            std::cout << "B created." << std::endl;
            return new B();
        default:
            std::cout << "C created." << std::endl;
            return new C();
    }
}

void    identify( Base *p ) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void    identify( const Base &p ) {
    if (dynamic_cast<const A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<const B *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<const C *>(&p))
        std::cout << "C" << std::endl;
}


int main( int, char** ) {
    std::srand(static_cast<unsigned>(std::time(0)));

    Base    *test = generate();
    identify(test);
    identify(*test);
    delete test;
}
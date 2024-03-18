#include "Span.hpp"
#include <cstdlib>
#include <algorithm>

int main() {
    Span test = Span(11);

    for (int i = 0; i < 9; i++) {
        test.addNumber(i);
    }
    test.addNumber(99999999);
    try {
        test.addNumber(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;

    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );
    
        Span aaa( l.size() );

        aaa.addNumber( l.begin(), l.end() );

        std::cout << aaa.longestSpan() << std::endl;
        std::cout << aaa.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
}
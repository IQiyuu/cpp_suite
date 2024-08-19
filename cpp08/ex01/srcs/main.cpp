#include "Span.hpp"
#include <cstdlib>

int main() {
    try {
        Span test = Span(10);
        for (int i = 0; i < 9; i++) {
            test.addNumber(i);
        }
        test.addNumber(99999999);
        std::cout << "longest span : " << test.longestSpan() << std::endl;
        std::cout << "shortest span: " << test.shortestSpan() << std::endl;
        // lst full
        test.addNumber(1);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    try {
        std::cout << std::endl;
        std::cout << "test 2" << std::endl;
        std::list<int>    l;
        std::srand( time ( NULL ) );
        for (int i = 0; i < 1000; i++)
            l.push_back(rand());
    
        Span aaa( l.size() );
        std::list<int> tmp = aaa.getList();
        std::cout << "Span size: " << l.size() << " empty" << std::endl;
        for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            std::cout << (*it) << "*";

        aaa.addNumber( l.begin(), l.end() );
        tmp = aaa.getList();
        std::cout << "Span size: " << l.size() << " filled" << std::endl;
        for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            std::cout << (*it) << "-";
        std::cout << std::endl;
        std::cout << "longest span : " << aaa.longestSpan() << std::endl;
        std::cout << "shortest span: " << aaa.shortestSpan() << std::endl;
        aaa.addNumber( l.begin(), l.end() );
    } catch ( std::exception& e ) {
        std::cout << "Error: " << e.what() << std::endl; 
    }
}


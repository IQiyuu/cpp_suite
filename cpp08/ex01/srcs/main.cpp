#include "Span.hpp"

int main() {
    Span test = Span(10000);
    Span aaa = Span(10000);

    for (int i = 0; i < 9999; i++) {
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

    aaa.addNumber(test.getList().begin(), test.getList().end());
    std::cout << aaa.shortestSpan() << std::endl;
    std::cout << aaa.longestSpan() << std::endl;
}
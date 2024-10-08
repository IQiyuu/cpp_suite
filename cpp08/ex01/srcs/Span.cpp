#include "Span.hpp"

Span::Span( unsigned int size ): _size(size){
    std::cout << "list \033[32mconstructed\033[0m" << std::endl;
}

Span::Span( const Span &ref ): _size(ref._size){
    std::cout << "list copy \033[32mconstructed\033[0m" << std::endl;
}

void Span::operator=( const Span &ref ){
    _size = ref._size;
    std::cout << "assignation" << std::endl;
}

Span::~Span( void ) {
    std::cout << "list \033[31mdestructed\033[0m" << std::endl;
}

void Span::addNumber( int n ) {
    if (_lst.size() < _size) {
        _lst.push_back(n);
        std::cout << n << " added to the list" << std::endl;
        return ;
    }
    throw std::out_of_range("Span::addNumber: list is full");
}

void Span::addNumber( std::list<int>::iterator start, std::list<int>::iterator end ) {
    int a = 0;
    for (std::list<int>::iterator it = start; it != end; it++)
        a++;
    if (_lst.size() + a > _size)
        throw std::out_of_range("Span::addNumber: list is full");
    this->_lst.insert( this->_lst.end(), start, end );
    std::cout << "span added" << std::endl;
}

int Span::shortestSpan( void ) {
    std::list<int>::iterator it;
    std::list<int>::iterator itcpy;
    int             shortest = -1;

    for (it = _lst.begin(); it != _lst.end(); it++) {
        itcpy = it;
        while (++itcpy != _lst.end()) {
            //  std::cout << *it << " " << *itcpy << " " << std::abs(*it - *itcpy) << std::endl;
            if (shortest == -1)
                shortest = std::abs(*it - *itcpy);
            else if (shortest > std::abs(*it - *itcpy))
                shortest = std::abs(*it - *itcpy);
            if (shortest == 0)
                return (shortest);
        }
    }
    return (shortest);
}

int Span::longestSpan( void ) {
    std::list<int>::iterator it;
    std::list<int>::iterator itcpy;
    int             longest = -1;

    for (it = _lst.begin(); it != _lst.end(); it++) {
        itcpy = it;
        while (++itcpy != _lst.end()) {
            //  std::cout << *it << " " << *itcpy << " " << std::abs(*it - *itcpy) << std::endl;
            if (longest == -1)
                longest = std::abs(*it - *itcpy);
            else if (longest < std::abs(*it - *itcpy))
                longest = std::abs(*it - *itcpy);
        }
    }
    return (longest);
}

const char* Span::ListOverflowException::what() const throw() {
    return "Too much arguments in the list.";
}

std::list<int> Span::getList( void ) const {
    return (this->_lst);
}
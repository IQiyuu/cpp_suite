#ifndef SPAN
#define SPAN

#include <iostream>
#include <cmath>
#include <list>

class Span {
    private:
        std::list<int> _lst;
        unsigned int _size;
        Span( void );
    
    public:
        Span( unsigned int );
        Span( const Span & );
        void operator=( const Span & );
        ~Span( void );

        void    addNumber( int );
        int     shortestSpan( void );
        int     longestSpan( void );

    class ListOverflowException: public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Too much arguments in the list.";
            }
    };

};

#endif
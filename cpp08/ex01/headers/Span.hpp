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
        void    addNumber( std::list<int>::iterator, std::list<int>::iterator );
        int     shortestSpan( void );
        int     longestSpan( void );

        std::list<int> getList( void ) const;

    class ListOverflowException: public std::exception {
        public:
            const char* what() const throw();
    };

};

#endif
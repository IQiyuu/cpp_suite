#ifndef PMERGE
#define PMERGE

#include <iostream>
#include <vector>
#include <list>
#include <ctime>   
#include <cstdlib> 
#include <cstring>

class PmergeMe {

    private:
        std::vector<int>    _vect;
        std::list<int>      _lst;
        PmergeMe( void );

    public:
        PmergeMe( int, char ** );
        PmergeMe( const PmergeMe & );
        PmergeMe &operator=( const PmergeMe & );
        ~PmergeMe( void );

        void sortAll( void );

        std::vector<int>    getVect( void ) const;
        std::list<int>      getList( void ) const;

        template <typename T>
        T       sort( T & );
        template <typename T>
        void    merge( T &, const typename T::value_type & );
        template <typename T>
        void    displayContainer( T & );

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Invalid Input."; }
            };
};

#endif
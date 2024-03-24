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

        template <typename T>
        T sort( T & );
        template <typename T>
        T merge( T &, T & );
        template <typename T>
        void    displayContainer( T & );
};

#endif
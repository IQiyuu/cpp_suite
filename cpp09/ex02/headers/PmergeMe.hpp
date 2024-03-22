#ifndef PmergeMe
#define PMERGE

#include <iostream>
#include <vector>
#include <list>
#include <ctime>   
#include <cstdlib> 

class PmergeMe {

    private:
        std::vector<int>    _vect;
        std::list<int>      _lst;
        PmergeMe( void );

    public:
        PmergeMe( char * );
        PmergeMe( const PmergeMe & );
        PmergeMe &operator=( const PmergeMe & );
        ~PmergeMe( void );

        void sortVector( void );
        void sortList( void );
        template <typename T>
        void displayContainer( T & );
        void displayResultContainer( T & );
};

#endif
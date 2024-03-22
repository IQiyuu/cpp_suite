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

        void sortVector( void );
        void sortList( void );
        template <typename T>
        void displayContainer( T &seq ) {
            typename T::iterator it;
            int cpt = 0;

            for (it = seq.begin(); it != seq.end(); it++) {
                if (seq.size() > 6 && (cpt < 3 || cpt > seq.size() - 4))
                    std::cout << *it << " ";
                if (seq.size() > 6 && cpt == 3)
                    std::cout << "[...] ";
                cpt++;
            }
        }
};

#endif
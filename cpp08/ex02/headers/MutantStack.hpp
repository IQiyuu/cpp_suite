#ifndef MUTANT
# define MUTANT

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
    public:
        MutantStack( void ): std::stack<T>(){ std::cout << "Mutant stack \033[32mcreated\033[0m"};
        MutantStack( const MutantStack &ref ) { *this = ref; }
        void operator=( const MutantStack &ref ) { *this = ref; }
}

#endif
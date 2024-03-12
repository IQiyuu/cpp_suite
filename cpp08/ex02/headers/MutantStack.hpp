#ifndef MUTANT
# define MUTANT

#include <iostream>
#include <stack>

template <typename T, class container=std::deque<T> >
class MutantStack: public std::stack<T> {
    public:
        MutantStack( void ): std::stack<T>() { std::cout << "Mutant stack \033[32mcreated\033[0m\n"; }
        MutantStack( const MutantStack &ref ) { *this = ref; }
        MutantStack *operator=( const MutantStack &ref ) { (void)ref; return *this; }
        ~MutantStack( void ) { std::cout << "Mutant stack \033[31mdeleted\033[0m\n"; }
        typedef typename container::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
        iterator operator++() {
            iterator temp = this->c;
            this->c++;
            return temp;
        }
        iterator operator--() {
            iterator temp = this->c;
            this->c++;
            return temp;
        }
};

#endif
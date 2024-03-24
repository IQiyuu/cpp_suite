#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

PmergeMe::PmergeMe( int n, char **args ) {
    char **tmp = NULL;
    std::cout << "PmergeMe \033[32mcreated\033[0m" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < (int)strlen((const char *)args[i]); r++){
           if (!std::isdigit(args[i][r])) {
                std::cout << "Error: `" << args[i] << " isn't a valid input" << std::endl;
                continue ;
           }
        }
        long num = std::strtol(args[i], tmp, 10);
        if (num < 0 || (int)strlen((const char *)args[i]) > 10) {
            std::cout << "Error: `" << args[i] << " isn't a valid input" << std::endl;
            continue ;
        }
        this->_lst.push_front(num);
        this->_vect.push_back(num);
    }
}

PmergeMe::PmergeMe( const PmergeMe &ref ) {
    *this = ref;
}

PmergeMe &PmergeMe::operator=( const PmergeMe &ref ) {
    this->_vect = ref._vect;
    this->_lst = ref._lst;
    return *this;
}

PmergeMe::~PmergeMe( void ) {
    std::cout << "PmergeMe \033[31mdeleted\033[0m" << std::endl;
}

void PmergeMe::sortAll( void ) {
    std::list<int>      sortedLst = sort( this->_lst );
    std::vector<int>    sortedVect = sort( this->_vect );
    displayContainer(sortedLst);
    displayContainer(sortedVect);
}
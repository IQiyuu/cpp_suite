#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

PmergeMe::PmergeMe( int n, char **args ) {
    char **tmp = NULL;
    std::cout << "PmergeMe \033[32mcreated\033[0m" << std::endl;
    for (int i = 1; i < n; i++) {
        for (int r = 0; r < (int)strlen((const char *)args[i]); r++){
           if (!std::isdigit(args[i][r])) {
                throw InvalidInputException();
           }
        }
        long num = std::strtol(args[i], tmp, 10);
        if (num > 0 && (int)strlen((const char *)args[i]) >  10) {
            throw InvalidInputException();
        }
        this->_lst.push_back(num);
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
    std::clock_t lst_clock;
    std::clock_t vect_clock;

    std::cout << "Before: " << std::endl;
    displayContainer(this->_lst);
    displayContainer(this->_vect);
    std::cout << std::endl;

    lst_clock = std::clock();
    std::list<int>      sortedLst = sort( this->_lst );
    double lst_time = static_cast<double>(std::clock() - lst_clock) / CLOCKS_PER_SEC * 1000;

    vect_clock = std::clock();
    std::vector<int>    sortedVect = sort( this->_vect );
    double vect_time = static_cast<double>(std::clock() - vect_clock) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: " << std::endl;
    displayContainer(sortedLst);
    displayContainer(sortedVect);

    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->_lst.size() << " elements with std::list: " << lst_time  << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_vect.size() << " elements with std::vect: " << vect_time << " us" << std::endl;

}

std::vector<int>    PmergeMe::getVect( void ) const { return this->_vect; }
std::list<int>      PmergeMe::getList( void ) const { return this->_lst; }
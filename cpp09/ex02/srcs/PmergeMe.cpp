#include "PmergeMe.cpp"

PmergeMe::PmergeMe( int n, char *args ) {
    std::cout << "PmergeMe \033[32mcreated\033[0m" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < strlen(args[i]); r++){
           if (!std::isdigit(args[i][r])) {
                std::cout << "Error: `" << args[i] << " isn't a valid input" << std::endl;
                continue ;
           }
        }
        long num = std::strtol(args[i]);
        if (num < 0 || strlen(args[i]) > 10) {
            std::cout << "Error: `" << args[i] << " isn't a valid input" << std::endl;
            continue ;
        }
        this->_lst.push_front(num);
        this->_vect.push_back(num);
    }
}

PmergeMe::~PmergeMe( void ) {
    std::cout << "PmergeMe \033[31mdeleted\033[0m" << std::endl;
}

PmergeMe &operator=( const PmergeMe &ref ) {
    this->_vect = ref.vect;
    this->_lst = ref.lst;
    return *this;
}

PmergeMe::PmergeMe( const PmergeMe &ref ) {
    *this = ref;
}
#ifndef EASY
#define EASY

#include <iostream>

class IntNotFoundException: public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Int not find in container.";
            }
    };

template<typename T>
void easyFind(T array, int entier) {
    typename T::iterator it;

    for (it = array.begin(); it != array.end(); it++) {
        if (*it == entier) {
            std::cout << "FOUND" << std::endl;
            return ;
        }
    }
    throw IntNotFoundException();
}

#endif
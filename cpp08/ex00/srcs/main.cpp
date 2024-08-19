#include "Easyfind.hpp"
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;

    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(25);
    vec.push_back(42);

    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it2 = vec.end();
    std::cout << "vector: ";
    while (it != it2) {
        std::cout << (*it) << "-";
        it++;
    }
    std::cout << std::endl;
    try {
        ::easyFind(vec, 5);
        ::easyFind(vec, 25);
        ::easyFind(vec, 45);
    } catch ( std::exception &e ) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::list<int> lst;

    lst.push_back(0);
    lst.push_back(2);
    lst.push_back(5);
    lst.push_back(25);
    lst.push_back(42);

    std::list<int>::iterator it3 = lst.begin();
    std::list<int>::iterator it4 = lst.end();
    std::cout << "list: ";
    while (it3 != it4) {
        std::cout << (*it3) << "-";
        it3++;
    }
    std::cout << std::endl;
    try {
        ::easyFind(lst, 0);
        ::easyFind(lst, 2);
        ::easyFind(lst, 45);
    } catch ( std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}
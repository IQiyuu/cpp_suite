#include "Easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> vec;

    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(25);
    vec.push_back(42);
    try {
        ::easyFind(vec, 5);
        ::easyFind(vec, 25);
        ::easyFind(vec, 45);
    } catch ( std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}
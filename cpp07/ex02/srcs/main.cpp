#include "Array.hpp"

int main( void ) {
    Array<int> numbers(750);
    int* mirror = new int[750];
    srand(time(NULL));
    for (int i = 0; i < 750; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp;
        try {
            for (int i = 0; i < 750 + 1; i++)
                std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << "\t";
            std::cout << "> too high" << std::endl;
        }
        tmp = numbers;
        Array<int> test(tmp);

        try {
            for (int i = 0; i < 750 + 1; i++) {
                if (tmp[i] != test[i]){
                    std::cerr << "didn't save the same value!!" << std::endl;
                    return 1;
                }
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << "\t";
            std::cout << "> too high" << std::endl;
        }

        std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

        test[1] = 123456789;

        std::cout << "test[1]:\t" << test[1] << std::endl;
        std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;
    }

    for (int i = 0; i < 750; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\t";
        std::cout << "> -2" << std::endl;
    }
    try {
        numbers[750] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\t";
        std::cout << "> too high" << std::endl;
    }

    for (int i = 0; i < 750; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "program arguments should be: ./btc file_path" << std::endl;
        return 1;
    }
    (void)av;
    BitcoinExchange base("./data.csv");
    return 0;
}
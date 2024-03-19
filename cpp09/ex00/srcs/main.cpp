#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "program arguments should be: ./btc file_path" << std::endl;
        return 1;
    }
    BitcoinExchange base("./data.csv");
    const std::string filename(av[1]);
    base.exchange(filename);
    return 0;
}
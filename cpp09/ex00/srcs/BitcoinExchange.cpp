#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( const char *filename ) {
    std::cout << "BitcoinExchange \03332mcreated\033[0m" << std::endl;
    this->_data = loadFile(filename);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &ref ) {
    *this = ref;
}

BitcoinExchange::~BitcoinExchange( void ) {
    std::cout << "BitcoinExchange \03331mdeleted\033[0m" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &ref ) {
    this->_data = ref._data;
    return *this;
}

std::map<std::string, double> BitcoinExchange::loadFile( const char *filename ) {
    std::ifstream in;
    std::map<std::string, double> ret;
    std::string line;
    std::string date;
    double value;
    std::stringstream ss;
    
    

    in.open(filename);
    if (!in.is_open())
        throw UnknowFileException();
    if (!std::getline(in, line))
        return ret;
    while(std::getline(in, line)) {
        std::cout << line << std::endl;
        date = line.substr(0, line.find('|'));
        ss << line.substr(line.find('|'), line.size());
        ss >> value;
        this->_data.insert(std::pair<std::string,double>(date, value));
    }
    return ret;
}

void    BitcoinExchange::writeData( void ) {
    std::map<std::string, double>::iterator it;

    for (it = this->_data.begin(); it != this->_data.end(); it++)
        std::cout << it->first << ':' << it->second << std::endl;
}
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( const char *filename ) {
    std::cout << "BitcoinExchange \033[32mcreated\033[0m" << std::endl;
    std::ifstream in(filename);
    std::string line;
    std::string file(filename);

    if (!in.is_open()) {
        std::cout << "Error in file opening : `" << file << "`" << std::endl;
        return ;
    }
    std::getline(in, line);
    while (std::getline(in, line)) {
        std::string::size_type delPos = line.find(',');
        if (delPos == std::string::npos) {
            std::cout << "The line: `" << line << "` don't have the good format in db" << std::endl;
            return ;
        }

        double value;

        std::string valueStr = line.substr(delPos + 1, line.size());
        std::string date = line.substr(0, delPos);

        std::stringstream ss(valueStr);
        if (!(ss >> value)) {
            std::cerr << "Invalid value format: `" << valueStr << "` in db" << std::endl;
			continue;
        }
        this->_data[date] = value;
    }
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &ref ) {
    *this = ref;
}

BitcoinExchange::~BitcoinExchange( void ) {
    std::cout << "BitcoinExchange \033[31mdeleted\033[0m" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &ref ) {
    this->_data = ref._data;
    return *this;
}

bool BitcoinExchange::validDate( std::string date ) {
    std::string::size_type del1 = date.find('-');
    std::string::size_type del2 = date.rfind('-');

    if (del1 == std::string::npos || del1 == del2)
		return false;

    std::string year = date.substr(0, del1);
    std::string month = date.substr(del1 + 1, del2 - del1 - 1);
    std::string day = date.substr(del2 + 1);

    std::istringstream yearSS(year);
    std::istringstream monthSS(month);
    std::istringstream daySS(day);

    int yearValue, monthValue, dayValue;

    if (!(yearSS >> yearValue) || !(monthSS >> monthValue) || !(daySS >> dayValue))
        return false;
    if (yearValue < 0 || monthValue < 1 || monthValue > 12 || dayValue < 1 || dayValue > 31)
        return false;
    if ((yearValue == 4 || yearValue == 6 || yearValue == 9 || yearValue == 11) && dayValue == 31)
        return false;
    if (monthValue == 2) {
        int leap = (!(yearValue % 4) && ((yearValue % 100) || !(yearValue % 400)));
        if ((leap && dayValue > 29) || (!leap && dayValue > 28))
            return false;
    }
    return true;
}

void BitcoinExchange::exchange( const std::string &filename ) {
    std::ifstream in(filename.data());
    std::string file(filename);
    std::string line;

    if (!in.is_open()) {
        std::cout << "Error in file opening : `" << file << "`" << std::endl;
        return ;
    }
    std::getline(in, line);
    while (std::getline(in, line)) {
        std::istringstream ss(line);

        std::string date;
		double value;
		char del;

        if (!(ss >> date >> del >> value)) {
            std::cout << "Error: Unable to parse line: `" << line << "`" << std::endl;
			continue ;
        }

        if (del != '|') {
            std::cout << "Error: Unvalid delimiter: `" << del << "`" << std::endl;
            continue ;
        }

        if (!validDate(date)) {
            std::cout << "Error: Unvalid date: `" << date << "`" << std::endl;
            continue ;
        }

        if ((value < 0 || value > 1000)) {
            std::cout << "Error: Unvalid value: `" << value << "`" << std::endl;
            continue ;
        }

        std::map<std::string, double>::iterator it = this->_data.lower_bound(date);

        if (it->first != date || it != this->_data.begin())
            it--;
        if (it != this->_data.end() || !this->_data.empty())
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        else
            std::cout << "No value for the date: `" << date << "`" << std::endl;
    }
}
#ifndef BTC
# define BTC

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;
        BitcoinExchange( void );
        std::map<std::string, double> loadFile( const char * );

    public:
        BitcoinExchange( const char * );
        BitcoinExchange( const BitcoinExchange & );
        ~BitcoinExchange( void );
        BitcoinExchange &operator=( const BitcoinExchange & );
        void writeData( void );

    class UnknowFileException: public std::exception {
        public:
            virtual const char* what() const throw() {
                return "This file does not exist.";
            }
    };
};

#endif
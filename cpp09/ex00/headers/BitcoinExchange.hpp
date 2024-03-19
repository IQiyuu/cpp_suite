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
        bool validDate( std::string date );

    public:
        BitcoinExchange( const char * );
        BitcoinExchange( const BitcoinExchange & );
        ~BitcoinExchange( void );
        BitcoinExchange &operator=( const BitcoinExchange & );
        void exchange( const std::string &filename );
};

#endif
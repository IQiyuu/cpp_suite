#ifndef SCALAR
#define SCALAR

#include "InputException.hpp"
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

#define FLOAT 'f'
#define INT 'i'
#define CHAR 'c'
#define DOUBLE 'd'

class ScalarConverter {
    private:
        static double   convertToDouble( std::string );
        static int      convertToInt( std::string );
        static float    convertToFloat( std::string );

    public:
        ScalarConverter( void );
        ScalarConverter( const ScalarConverter & );
        ScalarConverter &operator=( const ScalarConverter & );
        virtual ~ScalarConverter( void ) = 0;
        static void convert( std::string str );

};

#endif
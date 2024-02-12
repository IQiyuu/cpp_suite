#ifndef SCAL
# define SCAL

#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
    private:
        ScalarConverter( void );
        virtual ~ScalarConverter( void );

        static char    convertToChar( std::string str ) {
            std::istringstream is(str.substr(0, str.find(".")));
            int n;

            if (str == "nan") {
                std::cout << "impossible" << std::endl;
                return 0;
            }
            is >> n;
            if (n < 33 || n > 126) {
                std::cout << "Non displayable" << std::endl;
                return 0;
            }
            std::cout << "'" << (char)n << "'" << std::endl;
            return n;
        }

        static int convertToInt( std::string str ) {
            std::istringstream is(str.substr(0, str.find(".")));
            int n;

            if (str == "nan") {
                std::cout << "impossible" << std::endl;
                return 0;
            }
            if (is >> n) {
                std::cout << n << std::endl;
                return n;
            }
            return 0;
        }

        static float    convertToFloat( std::string str ) {
            float f;
            std::istringstream bg(str);

            if (str == "nan") {
                std::cout << "nanf" << std::endl;
                return 0;
            }
            if (bg >> f) {
                std::cout << f;
                if (str.find("."))
                return f;
            }
            return 0;
        }

        static double    convertToDouble( std::string str ) {
            double f;
            std::istringstream bg(str);

            if (str == "nan") {
                std::cout << "nan" << std::endl;
                return 0;
            }

            if (bg >> f) {
                std::cout << f << std::endl;
                return f;
            }
            return 0;
        }


    public:
        static void convert( std::string str ) {

            std::cout << "char: ";
            convertToChar(str);
            std::cout << "int: ";
            convertToInt(str);
            std::cout << "float: ";
            convertToFloat(str);
            std::cout << "double: ";
            convertToDouble(str);
        }
};

#endif
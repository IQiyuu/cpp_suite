#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}
ScalarConverter::ScalarConverter( const ScalarConverter &ref ) { *this = ref; }
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &ref ) {
    (void) ref;
    return *this;
}

int isallnum( std::string str ) {
    for (int i = (str[0] == '-' ? 1 : 0); i < static_cast<int>(str.size()); i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}

int isprint2( int i ) {
    if (i >= 33 && i <= 126)
        return 1;
    return 0;
}

float   ScalarConverter::convertToFloat( std::string str ) {
    float   f;
    char    *end;
    errno = 0;

    f = std::strtof(str.data(), &end);

    if (*(end+1) != '\0')
        throw InputException("Input not valid.");
    if (errno == ERANGE)
        throw InputException("Float overflow.");

    return f;
}

double   ScalarConverter::convertToDouble( std::string str ) {
    double   d;
    char    *end;
    errno = 0;

    d = std::strtod(str.data(), &end);

    if (*end != '\0')
        throw InputException("Input not valid.");
    if (errno == ERANGE) {
        throw InputException("Double overflow.");
    }
    return d;
}

int   ScalarConverter::convertToInt( std::string str ) {
    int   i;
    std::stringstream ss(str);

    if (((str[0] != '-' && (str.size() > 10 || (str.size() == 10 && str.compare("2147483647") > 0))) ||
        (str[0] == '-' && (str.size() > 11 || (str.size() == 11 && str.compare("-2147483648") > 0)))))
            throw InputException("Int overflow.");

    ss >> i;
    return i;
}

void    ScalarConverter::convert( std::string str ) {
    float   f = 0;
    int     i = 0;
    char    c = 0;
    double  d = 0;

    try {
        if (str.empty())
            throw InputException("Empty input.");
        else if (str.find("f") != std::string::npos && str.size() != 1) {
            f = convertToFloat(str);
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
        } else if (str.find(".") != std::string::npos) {
            d = convertToDouble(str);
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
        } else if (isallnum(str)) {
            i = convertToInt(str);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        } else if (str.size() == 1) {
            c = str[0];
            f = static_cast<float>(c);
            i = static_cast<int>(c);
            d = static_cast<double>(c);
        } else if (str.compare("nan") == 0) {
            d = convertToDouble(str);
            f = static_cast<float>(d);
        } else
            throw InputException("Input not valid.");
        if (!str.compare("nan") || !str.compare("nanf") || !str.compare("+inf") || !str.compare("+inff") || !str.compare("-inff") || !str.compare("-inf")) {
            std::cout << "* char  : impossible" << std::endl;
            std::cout << "* int   : impossible" << std::endl;
        } else {
            std::cout << "* char  : " << (isprint2(i) ? std::string(1, c) : "Non displayable") << std::endl;
            std::cout << "* int   : " << i << std::endl;
        }
        if (str.find('.') == std::string::npos)
            std::cout << std::fixed << std::setprecision(1);
        else 
            std::cout << std::fixed << std::setprecision(str.substr(str.find('.') + 1).length());
        std::cout << "* float : " << f << "f" << std::endl;
        std::cout << "* double: " << d << std::endl;
    } catch ( std::exception &e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
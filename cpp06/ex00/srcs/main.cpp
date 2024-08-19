#include "ScalarConverter.hpp"

int main( int, char ** ) {
	//ScalarConverter a;

	std::cout << "\nTest avec une phrase" << std::endl;
	ScalarConverter::convert("Quelle horeur!");

	std::cout << "\nTest avec un double bien trop grand" << std::endl;
	ScalarConverter::convert("45555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555552455555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555524555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555245555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555552.02");
	
	std::cout << "\nTest 42f2 (float invalide)" << std::endl;
	ScalarConverter::convert("42f2");

	std::cout << "\nTest 2147483648 (max int + 1)" << std::endl;
	ScalarConverter::convert("2147483648");

	std::cout << "\nTest 42f (float)" << std::endl;
	ScalarConverter::convert("42f");

	std::cout << "\nTest 4242.42 (double)" << std::endl;
	ScalarConverter::convert("4242.42");

	std::cout << "\nTest 0 (int)" << std::endl;
	ScalarConverter::convert("0");

	std::cout << "\nTest 2147483647 (max int)" << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << "\nTest avec 'c' (char)" << std::endl;
	ScalarConverter::convert("c");

	std::cout << "\nTest avec +inff (float)" << std::endl;
	ScalarConverter::convert("-inff");

	std::cout << "\nTest avec +inf (double)" << std::endl;
	ScalarConverter::convert("+inf");

	std::cout << "\nTest avec nan (double)" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << "\nTest avec nanf (float)" << std::endl;
	ScalarConverter::convert("nanf");
	return 0;
}

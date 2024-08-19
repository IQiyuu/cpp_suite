#include "Iter.hpp"

void ft_tolower( char &arr ) {
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper( char &arr ) {
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void ft_decremente( int &arr ) {
	arr--;
}

void ft_incremente( int &arr ) {
	arr++;
}

int main( void ) {
	std::cout << std::endl;
	std::cout << "Test char[]" << std::endl;
	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter(a, sizeof(a) / sizeof(char), ft_tolower);

	std::cout << "lower:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter(a, sizeof(a) / sizeof(char), ft_toupper);

	std::cout << "upper:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Test int[]" << std::endl;
	int b[] = { 1, 2, 3};

	std::cout << "Original:" <<
	"\n\tb[0]: " << b[0] <<
	"\n\tb[1]: " << b[1] <<
	"\n\tb[2]: " << b[2] <<
	std::endl << std::endl;

	::iter(b, sizeof(b) / sizeof(int), ft_incremente);

	std::cout << "lower:" <<
	"\n\tb[0]: " << b[0] <<
	"\n\tb[1]: " << b[1] <<
	"\n\tb[2]: " << b[2] <<
	std::endl << std::endl;

	::iter(b, sizeof(b) / sizeof(int), ft_decremente);

	std::cout << "upper:" <<
	"\n\tb[0]: " << b[0] <<
	"\n\tb[1]: " << b[1] <<
	"\n\tb[2]: " << b[2] <<
	std::endl << std::endl;
}
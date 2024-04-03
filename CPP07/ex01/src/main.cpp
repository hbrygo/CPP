#include "../includes/iter.hpp"
#include <iostream>

void display( int x ) {
	std::cout << "Number " << x << std::endl;
}

int display_char( char c ) {
	std::cout << "Character " << c << std::endl;
	return (0);
}

int	main( void ) {
	int intarray[6] = {0, 6, 89, 42, 999};
	iter(intarray, 5, display);

	std::string str = "magic";
	const char *chararray = str.c_str();
	iter(chararray, 5, display_char);
	return (0);
}
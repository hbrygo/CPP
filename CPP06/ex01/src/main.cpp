#include "../includes/Serializer.hpp"
#include <iostream>

int	main( void ) {
	Data original = { 18 };
	uintptr_t tmp = Serializer::serialize( &original );
	Data* copy = Serializer::deserialize( tmp );

	std::cout << original.value << " - " << copy->value << std::endl;

	return (0);
}
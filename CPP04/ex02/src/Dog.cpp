#include "../includes/Dog.hpp"

Dog::Dog( void ){
	std::cout << "Default constructor dog called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog &other ) :Animal( other ){
	std::cout << "Copy constructor dog called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog(){
	std::cout << "Default destructor dog called" << std::endl;
}

Dog& Dog::operator=( const Dog &other ){
	std::cout << "Copy assignment operator dog called" << std::endl;
	(void)other;
	this->_type = "Dog";
	return *this;
}

void Dog::makeSound( void ) const{
	std::cout << "Wouf" << std::endl;
}
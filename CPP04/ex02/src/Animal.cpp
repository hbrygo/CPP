#include "../includes/Animal.hpp"

Animal::Animal( void ){
	std::cout << "Default constructor animal called" << std::endl;
	this->_type = "None";
}

Animal::Animal( const Animal& other) : _type(other._type){
	std::cout << "Copy constructor animal called" << std::endl;
	return ;
}

Animal::~Animal(){
	std::cout << "Default destructor animal called" << std::endl;
}

Animal &Animal::operator=( const Animal &other ) {
	std::cout << "Copy assignment operator of Animal called" << std::endl;
	this->_type = other._type;
	return *this;
}

std::string Animal::getType( void ) const{
	return this->_type;
}

void Animal::makeSound( void ) const{
	std::cout << "Nothing to hear" << std::endl;
}

Brain* Animal::getBrain() const{
	return NULL;
}
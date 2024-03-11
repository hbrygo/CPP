#include "../includes/Animal.hpp"

Animal::Animal( void ){
	std::cout << "Default constructor animal called" << std::endl;
	this->_type = "None";
	this->_brain = new Brain;
}

Animal::Animal( const Animal& other){
	std::cout << "Copy constructor animal called" << std::endl;
	this->_brain = new Brain;
	*this = other;
	return ;
}

Animal::~Animal(){
	std::cout << "Default destructor animal called" << std::endl;
	delete this->_brain;
}

Animal &Animal::operator=( const Animal &other ) {
	std::cout << "Copy assignment operator of Animal called" << std::endl;
	this->_type = other._type;
	*this->_brain = *other._brain;
	return *this;
}

std::string Animal::getType( void ) const{
	return this->_type;
}

void Animal::makeSound( void ) const{
	std::cout << "Nothing to hear" << std::endl;
}
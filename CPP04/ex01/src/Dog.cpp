#include "../includes/Dog.hpp"

Dog::Dog( void ){
	std::cout << "Default constructor dog called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog &other ) :Animal( other ){
	std::cout << "Copy constructor dog called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain(*(other._brain));
	return ;
}

Dog::~Dog(){
	std::cout << "Default destructor dog called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=( const Dog &other ){
	std::cout << "Copy assignment operator dog called" << std::endl;
	*this->_brain = *other._brain;
	this->_type = "Dog";
	return *this;
}

void Dog::makeSound( void ) const{
	std::cout << "Wouf" << std::endl;
}

Brain* Dog::getBrain() const{
	return this->_brain;
}
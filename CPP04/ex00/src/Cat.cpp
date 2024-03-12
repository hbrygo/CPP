#include "../includes/Cat.hpp"

Cat::Cat( void ){
	std::cout << "Default constructor cat called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat( const Cat &other ) :Animal ( other ){
	std::cout << "Copy constructor cat called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::~Cat(){
	std::cout << "Default destructor cat called" << std::endl;
}

Cat& Cat::operator=( const Cat &other){
	std::cout << "Copy assignment operator cat called" << std::endl;
	(void)other;
	this->_type = "Cat";
	return *this;
}

void Cat::makeSound( void ) const{
	std::cout << "Miaou" << std::endl;
}
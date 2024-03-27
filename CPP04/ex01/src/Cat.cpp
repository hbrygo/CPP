#include "../includes/Cat.hpp"

Cat::Cat( void ){
	std::cout << "Default constructor cat called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat &other ) :Animal ( other ){
	std::cout << "Copy constructor cat called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain(*(other._brain));
	return ;
}

Cat::~Cat(){
	std::cout << "Default destructor cat called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=( const Cat &other){
	std::cout << "Copy assignment operator cat called" << std::endl;
	*this->_brain = *other._brain;
	this->_type = "Cat";
	return *this;
}

void Cat::makeSound( void ) const{
	std::cout << "Miaou" << std::endl;
}

Brain* Cat::getBrain() const{
	return this->_brain;
}
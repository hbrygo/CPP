#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){
	std::cout << "Default constructor wrong_animal called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ){
	std::cout << "Copy constructor wrong_animal called" << std::endl;
	*this = other;
	return ;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Default destructor wrong_animal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ){
	std::cout << "Copy assignment operator of wrong_Animal called" << std::endl;
	this->_type = other._type;
	return *this;
}

void WrongAnimal::makeSound( void ) const{
	std::cout << "Wrong sound" << std::endl;
}

std::string WrongAnimal::getType( void ) const{
	return this->_type;
}
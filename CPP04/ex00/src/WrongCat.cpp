#include "../includes/Wrongcat.hpp"

WrongCat::WrongCat( void ){
	std::cout << "Default constructor wrong_cat called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) :WrongAnimal( other ){
	std::cout << "Copy constructor wrong_cat called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::~WrongCat(){
	std::cout << "Default destructor wrong_cat called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other ){
	std::cout << "Copy assignment operator of wrong_cat called" << std::endl;
	(void)other;
	this->_type = "WrongCat";
	return *this;
}

void WrongCat::makeSoung( void ) const{
	std::cout << "Wrong miaou" << std::endl;
}


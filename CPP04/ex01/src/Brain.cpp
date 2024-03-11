#include "../includes/Brain.hpp"

Brain::Brain( void ){
	std::cout << "Default constructor brain called" << std::endl;
}

Brain::Brain( const Brain& other ){
	std::cout << "Copy constructor brain called" << std::endl;
    *this = other;
    return ;
}

Brain::~Brain(){
	std::cout << "Default destructor brain called" << std::endl;
}

Brain& Brain::operator=(const Brain& other ){
	std::cout << "Copy assignment operator of brain called" << std::endl;
    for (int i = 0; i < 100; i++){
        this->_ideas[i] = other._ideas[i];
    }
    return *this;
}
#include "../includes/Brain.hpp"

Brain::Brain( void ){
	std::cout << "Default constructor brain called" << std::endl;
    this->_newIdea = 0;
}

Brain::Brain( const Brain& other ){
	std::cout << "Copy constructor brain called" << std::endl;
    this->_newIdea = other._newIdea;
    for (int i = 0; i < 100; i++){
        this->_ideas[i] = other._ideas[i];
    }
    return ;
}

Brain::~Brain(){
	std::cout << "Default destructor brain called" << std::endl;
}

Brain& Brain::operator=(const Brain& other ){
	std::cout << "Copy assignment operator of brain called" << std::endl;
    this->_newIdea = other._newIdea;
    for (int i = 0; i < 100; i++){
        this->_ideas[i] = other._ideas[i];
    }
    return *this;
}

std::string Brain::getIdea( int i ){
    return this->_ideas[i];
}

void Brain::addIdea( const std::string idea ){
    this->_ideas[this->_newIdea] = idea;
    this->_newIdea++;
    if (this->_newIdea == 100)
        this->_newIdea = 0;
}

void Brain::setIdea( int i, const std::string idea ){
    this->_ideas[i] = idea;
}
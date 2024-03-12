#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "Default constructor FragTrap called" << std::endl;
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoint = 100;
	this->_name = "FragTrap Default";
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoint = 100;
	this->_name = name;
}

FragTrap::~FragTrap(){
    std::cout << "Default destructor FragTrap called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap() {
	std::cout << "Constructor copy FragTrap called" << std::endl;
	*this = other;
	return ;
}

FragTrap& FragTrap::operator=( const FragTrap& other ){
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
	this->_attackDamage = other._attackDamage;
	this->_energyPoint = other._energyPoint;
	this->_hitPoint = other._hitPoint;
	this->_name = other._name;
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << "Can i have a HIGH FIVE ????" << std::endl;
}
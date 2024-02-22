#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
    std::cout << "Default constructor ScavTrap called" << std::endl;
    this->_attackDamage = 20;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
    this->_name = "ScavTrap Default";
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
    this->_name = name;
    this->_attackDamage = 20;
    this->_energyPoint = 50;
    this->_hitPoint = 100;
}

ScavTrap::~ScavTrap(){
    std::cout << "Default destructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap() {
    std::cout << "Constructor copy ScavTrap called" << std::endl;
    *this = other;
    return ;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other ){
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    this->_attackDamage = other._attackDamage;
    this->_energyPoint = other._energyPoint;
    this->_hitPoint = other._hitPoint;
    this->_name = other._name;
    return *this;
}

void ScavTrap::guardGate(){
    std::cout << "Gate keeper mode activated" << std::endl;
}
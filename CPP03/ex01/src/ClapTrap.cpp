#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ){
    std::cout << "Default constructor ClapTrap called" << std::endl;
    this->_attackDamage = 0;
    this->_energyPoint = 10;
    this->_hitPoint = 10;
    this->_name = "ClapTrap Default";
}

ClapTrap::ClapTrap( std::string name ){
    this->_name = name;
    this->_attackDamage = 0;
    this->_energyPoint = 10;
    this->_hitPoint = 10;
}

ClapTrap::~ClapTrap(){
    std::cout << "Default destructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ){
    std::cout << "Constructor copy ClapTrap called" << std::endl;
    *this = other;
    return ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other ){
    std::cout << "Copy assignment operator ClapTrap called" << std::endl;
    this->_attackDamage = other._attackDamage;
    this->_energyPoint = other._energyPoint;
    this->_hitPoint = other._hitPoint;
    this->_name = other._name;
    return *this;   
}

void ClapTrap::attack(const std::string& target){
    if (this->_energyPoint == 0){
        std::cout << "ClapTrap " << this->_name << " has no more energy for this action" << std::endl;
        return ;
    }
    else if (this->_hitPoint == 0){
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_energyPoint == 0){
        std::cout << "ClapTrap " << this->_name << " has no more energy for this action" << std::endl;
        return ;
    }
    else if (this->_hitPoint == 0){
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is attacked, he loses " << amount << " points of life!" << std::endl;
    this->_hitPoint -= amount;
    if (this->_hitPoint < 0)
        this->_hitPoint = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoint == 0){
        std::cout << "ClapTrap " << this->_name << " has no more energy for this action" << std::endl;
        return ;
    }
    else if (this->_hitPoint == 0){
        std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " repairs, he restores " << amount << " points of life!" << std::endl;
    this->_hitPoint += amount;
    this->_energyPoint--;
}
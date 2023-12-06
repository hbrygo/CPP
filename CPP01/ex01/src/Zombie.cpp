#include "../include/Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void	Zombie::addName(std::string name)
{
	_name = name;
}

void	Zombie::announce(int i)
{
	std::cout << "Zombie " << i + 1 << ": " << _name << std::endl;
}
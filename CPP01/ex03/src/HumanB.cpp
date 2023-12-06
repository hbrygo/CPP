#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::string type;

	type = _weapon->getType();
	std::cout << _name << " attacks with their " << type << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
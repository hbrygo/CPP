#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::string type;

	type = _weapon.getType();
	std::cout << _name << " attacks with their " << type << std::endl;
}
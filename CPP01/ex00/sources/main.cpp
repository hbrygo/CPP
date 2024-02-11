#include "../includes/Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int main (void)
{
	Zombie zombie = Zombie("Lucas");
	Zombie *newZ;

	newZ = newZombie("Carlos");
	newZ->announce();
	delete newZ;
	zombie.announce();
	randomChump("Adrian");
	return (0);
}
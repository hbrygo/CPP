#include "../include/Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie zombie("Olivier");
	Zombie *ptrZombie;

	zombie.announce();
	ptrZombie = newZombie("Eric");
	ptrZombie->announce();
	randomChump("Florian");
	delete ptrZombie;
	return (0);
}
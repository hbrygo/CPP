#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	Zombie *zomb;
	int N = 4;
	std::string name = "Karl";

	zomb = zombieHorde(N, name);
	for (int i = 0; i < 4; i++)
		zomb[i].announce(i);
	delete[] zomb;
	return (0);
}
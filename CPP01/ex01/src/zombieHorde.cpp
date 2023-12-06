#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *ptrZombie;

	ptrZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		ptrZombie[i].addName(name);
	return (ptrZombie);
}
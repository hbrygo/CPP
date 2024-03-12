#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    int numberOfZombie = 2;
    Zombie *zombie = zombieHorde(numberOfZombie, "Carlos");
    for (int i = 0; i < numberOfZombie; i++)
        zombie[i].announce();
    delete[] zombie;
}

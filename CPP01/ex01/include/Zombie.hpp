#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();

	void	announce(int i);
	void	addName(std::string name);
};

#endif
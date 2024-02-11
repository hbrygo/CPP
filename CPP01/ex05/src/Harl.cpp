#include "../include/Harl.hpp"

Harl::Harl()
{
	_fct[0] = &Harl::debug;
	_fct[1] = &Harl::info;
	_fct[2] = &Harl::warning;
	_fct[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	std::string comp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (comp[i] == level)
			(this->*(_fct[i]))();
	}
}
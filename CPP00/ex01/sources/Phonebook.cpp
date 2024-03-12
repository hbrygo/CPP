#include "../includes/Phonebook.hpp"

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

void Phonebook::init()
{
	this->_index = 0;
	this->_nbContact = 0;
}

void Phonebook::display_all()
{
	int	ind;
	std::string index;

	if (this->_nbContact == 0)
	{
		std::cout << "Your phonebook is empty" << std::endl;
		return ;
	}
	std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|" << std::endl;
	for (int i = 0; i < this->_nbContact; i++)
		this->_contact[i].display(i);
	std::cout << "Enter the number of the contact you want to watch: ";
	if (!std::getline(std::cin, index))
		exit (-1);
	if (index.size() != 1 || !isdigit(index[0]))
	{
		std::cout << "bad input, try with a digit" << std::endl;
		return ;
	}
	ind = (int)index[0] - 48;
	if (ind <= this->_nbContact && ind > 0)
		this->_contact[ind - 1].display_contact();
	else
		std::cout << "bad input, try with a digit between 1 and " << this->_nbContact << std::endl;
}

void Phonebook::add_contact(Contact new_contact)
{
	std::cout << this->_index << std::endl;
	std::cout << this->_nbContact << std::endl;
	if (this->_index == 8)
		this->_index = 0;
	this->_contact[this->_index] = new_contact;
	if (this->_nbContact != 8)
		this->_nbContact++;
	this->_index++;
}
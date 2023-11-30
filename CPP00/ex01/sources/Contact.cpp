#include "../includes/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::create()
{
	do
	{
		std::cout << "What's your first name? ";
		if (!std::getline(std::cin, this->_firstName))
			exit (-1);
	}while (this->_firstName.empty() == true);
	do
	{
		std::cout << "What's your last name? ";
		if (!std::getline(std::cin, this->_lastName))
			exit (-1);
	}while (this->_lastName.empty() == true);
	do
	{
		std::cout << "What's your nick name? ";
		if (!std::getline(std::cin, this->_nickName))
			exit (-1);
	}while (this->_nickName.empty() == true);
	do
	{
		std::cout << "What's your phone number? ";
		if (!std::getline(std::cin, this->_phoneNumber))
			exit (-1);
	}while (this->_phoneNumber.empty() == true);
	do
	{
		std::cout << "What's your darkest secret? ";
		if (!std::getline(std::cin, this->_darkestSecret))
			exit (-1);
	}while (this->_darkestSecret.empty() == true);
}

void	formate(std::string str)
{
	if (str.size() >= 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".|";
		return ;
	}
	std::cout << std::setw(10) << str;
	std::cout << "|";
}


void	Contact::display(int index)
{
	std::cout << "|" << std::setw(10) << index  + 1 << "|";
	formate(this->_firstName);
	formate(this->_lastName);
	formate(this->_nickName);
	std::cout << std::endl;
}

void	Contact::display_contact()
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nick name: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
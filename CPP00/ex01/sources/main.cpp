#include "../includes/Phonebook.hpp"

int main(void)
{
	std::string str;
	std::string	index;
	Phonebook book;

	book.init();
	do
	{
		std::cout << "Make a choice (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, str))
			return(-1);
		if (str == "ADD")
		{
			system("clear");
			Contact new_contact;
			new_contact.create();
			book.add_contact(new_contact);
		}
		else if (str == "SEARCH")
		{
			system("clear");
			book.display_all();
		}
		else if (str != "EXIT")
			std::cout << "bad inupt" << std::endl;
	}while (str != "EXIT");
	return (0);
}
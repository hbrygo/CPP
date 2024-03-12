#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact	_contact[8];
	int		_nbContact;
	int		_index;
public:
	Phonebook();
	~Phonebook();

	void display_all();
	void init();
	void add_contact(Contact new_contact);
};


#endif
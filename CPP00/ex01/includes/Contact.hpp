#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkestSecret;
	std::string _phoneNumber;
public:
	Contact();
	~Contact();

	void	create();
	void	display(int index);
	void	display_contact();
};


#endif
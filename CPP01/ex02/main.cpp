#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adresse de str: " << &str << std::endl;
	std::cout << "Adresse de strPTR: " << stringPTR << std::endl;
	std::cout << "Adresse de strREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Valeur de str: " << str << std::endl;
	std::cout << "Valeur de strPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur de strREF: " << stringREF << std::endl;
}
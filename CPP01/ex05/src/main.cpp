#include "../include/Harl.hpp"

int main()
{
	Harl test;
	std::cout << "______________________________________" << std::endl;
	std::cout << "Debug: " << std::endl; 
	test.complain("DEBUG");
	std::cout << "______________________________________" << std::endl;
	std::cout << "INFO: " << std::endl; 
	test.complain("INFO");
	std::cout << "______________________________________" << std::endl;
	std::cout << "WARNING: " << std::endl; 
	test.complain("WARNING");
	std::cout << "______________________________________" << std::endl;
	std::cout << "ERROR: " << std::endl; 
	test.complain("ERROR");
	std::cout << "______________________________________" << std::endl;
	std::cout << "Other: " << std::endl; 
	test.complain("Other");
}
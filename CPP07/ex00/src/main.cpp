#include "../includes/whatever.hpp"
#include <iostream>

int main() {
	std::cout << "--------------- MY MAIN ---------------" << std::endl;
	std::cout << "--------------- MAX ---------------" << std::endl;
	{
		std::cout << "MAX(1, 2): " << ::max(1, 2) << std::endl;
		std::cout << "MAX(-10, -3): " << ::max(-10, -3) << std::endl;
		std::cout << "MAX(75, -75): " << ::max(75, -75) << std::endl;
		std::cout << "MAX(75, 21): " << ::max(75, 21) << std::endl;
		std::cout << "MAX(r, a): " << ::max('r', 'a') << std::endl;
		std::cout << "MAX(bonjour, bonjoure): " << ::max("bonjour", "bonjoure") << std::endl;
	}
	std::cout << "--------------- MIN ---------------" << std::endl;
	{
		std::cout << "MIN(1, 2): " << ::min(1, 2) << std::endl;
		std::cout << "MIN(-10, -3): " << ::min(-10, -3) << std::endl;
		std::cout << "MIN(75, -75): " << ::min(75, -75) << std::endl;
		std::cout << "MIN(75, 21): " << ::min(75, 21) << std::endl;
		std::cout << "MIN(r, a): " << ::min('r', 'a') << std::endl;
		std::cout << "MIN(bonjour, bonjoure): " << ::min("bonjour", "bonjoure") << std::endl;
	}
	std::cout << "--------------- SWAP ---------------" << std::endl;
	{
		int	a = 1;
		int	b = 2;
		std::string s1 = "Bonjour";
		std::string s2 = "Aurevoir";
		char c1 = 'c';
		char c2 = 'D';
		std::cout << "a = " << a << ", b = " << b << ", s1 = " << s1 << ", s2 = " << s2 << ", c1 = " << c1 << ", c2 = " << c2 << std::endl;
		::swap(a, b);
		std::cout << "SWAP(a, b): " << a << " " << b << std::endl;
		::swap(s1, s2);
		std::cout << "SWAP(s1, s2): " << s1 << " " << s2 << std::endl;
		::swap(c1, c2);
		std::cout << "SWAP(c1, c2): " << c1 << " " << c2 << std::endl;
	}
	std::cout << "\n--------------- OUR MAIN ---------------" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
}
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>
#include <cstdlib>

class ScalarConverter{
	private:

	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& other );
		~ScalarConverter( void );
		ScalarConverter& operator=( const ScalarConverter& other );

		static void convert( std::string str );
};

#endif
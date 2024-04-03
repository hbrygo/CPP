#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other ){
	(void)other;
	return ;
}

ScalarConverter::~ScalarConverter( void ){
	std::cout << "Default destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ){
	(void)other;
	return *this;
}

static void convertToInt( double num ){
	std::cout << "Int: " << static_cast<int>(num) << "\n";
}

static void convertToChar( double num ){
	if (!isprint(static_cast<char>(num)))
		std::cout << "Char: Is not printable\n";
	else
		std::cout << "Char: '" << static_cast<char>(num) << "'\n";
}

static void convertToFloat( double num ){
	if (static_cast<int>(num) == num)
		std::cout << "Float: " << static_cast<float>(num) << ".0f\n";
	else
		std::cout << "Float: " << static_cast<float>(num) << "f\n";
}

void ScalarConverter::convert( std::string str ){
	try
	{
		char* endPtr = nullptr;
		const char* str2 = str.c_str();
		double num;
		if (str.length() == 1 && isascii(str[0])) {
			// std::cout << "str2: " << str2 << " len: " << str.length() << std::endl;
			int valueInt = str[0];
			num = valueInt;
		}
		else if (str.back() == 'f' && str.find('.') != std::string::npos) {
			str.back() = '\0';
			num = strtod(str2, &endPtr);
		}
		else{
		    num = strtod(str2, &endPtr);
		}
		// std::cout << "num: " << num << std::endl;
		if (num != num) {
			std::cout << "Int: nan" << std::endl;
			std::cout << "Char: nan" << std::endl;
			std::cout << "Float: nan" << std::endl;
			std::cout << "Double: nan" << std::endl;
			return ;
		}
		else if (str == "+inf" || str == "+inff") {
			std::cout << "Int: Is to High" << std::endl;
			std::cout << "Char: Is not printable" << std::endl;
			std::cout << "Float: +inff" << std::endl;
			std::cout << "Double: +inf" << std::endl;
			return ;
		}
		else if (str == "-inf" || str == "-inff") {
			std::cout << "Int: Is to low" << std::endl;
			std::cout << "Char: Is not printable" << std::endl;
			std::cout << "Float: -inff" << std::endl;
			std::cout << "Double: -inf" << std::endl;
			return ;
		}
		else if (num > 2147483647) {
			std::cout << "Int to High." << std::endl;
			std::cout << "Char: Is not printable" << std::endl;
			if (static_cast<int>(num) == num)
				std::cout << "Float: " << static_cast<float>(num) << ".0f" << std::endl;
			else
				std::cout << "Float: " << static_cast<float>(num) << "f" << std::endl;
			if (static_cast<int>(num) == num)
				std::cout << "Double: " << num << ".0" << std::endl;
			else
				std::cout << "Double: " << num << std::endl;
			return ;
		}
		else if (num < -2147483648) {
			std::cout << "Int to low." << std::endl;
			std::cout << "Char: Is not printable" << std::endl;
			if (static_cast<int>(num) == num)
				std::cout << "Float: " << static_cast<float>(num) << ".0f" << std::endl;
			else
				std::cout << "Float: " << static_cast<float>(num) << "f" << std::endl;
			if (static_cast<int>(num) == num)
				std::cout << "Double: " << num << ".0" << std::endl;
			else
				std::cout << "Double: " << num << std::endl;
			return ;
		}
		if (endPtr != nullptr && *endPtr != '\0') {
        	std::cout << "Error." << std::endl;
			return ;
    	}
		convertToInt(num);
		convertToChar(num);
		convertToFloat(num);
		if (static_cast<int>(num) == num)
			std::cout << "Double: " << num << ".0" << std::endl;
		else
			std::cout << "Double: " << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	
}

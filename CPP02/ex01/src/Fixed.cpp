#include "../includes/Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num )
{
    std::cout << "Int constructor called" << std::endl;
    this._number = num;
}

Fixed::Fixed( const float num )
{
    std::cout << "Float constructor called" << std::endl;
    this._num_bit = num;
}

Fixed::Fixed( const Fixed &other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this._number = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this._number;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this._number = raw;
}

float Fixed::toFloat( void ) const
{
}

int Fixed::toInt( void ) const
{
}
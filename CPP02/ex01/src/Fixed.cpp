#include "../includes/Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->_number = 0;
}

Fixed::Fixed( const int num )
{
    std::cout << "Int constructor called" << std::endl;
    this->_number = num << this->_num_bit;
}

Fixed::Fixed( const float num )
{
    std::cout << "Float constructor called" << std::endl;
    this->_number = roundf( num * ( 1 << _num_bit ));
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

Fixed& Fixed::operator=( const Fixed &other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_number = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_number;
}

void Fixed::setRawBits( int const raw )
{
	this->_number = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>( this->getRawBits() ) / ( 1 << this->_num_bit );
}

int Fixed::toInt( void ) const
{
    return this->_number >> this->_num_bit;
}

std::ostream& operator<<(std::ostream& f, Fixed const& i)
{
    f << i.toFloat();
    return f;
}
#include "../includes/Fixed.hpp"

Fixed::Fixed( void )
{
    this->_number = 0;
}

Fixed::Fixed( const int num )
{
    this->_number = num << this->_num_bit;
}

Fixed::Fixed( const float num )
{
    this->_number = roundf( num * ( 1 << _num_bit ));
}

Fixed::Fixed( const Fixed &other )
{
    *this = other;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=( const Fixed &other )
{
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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

bool    Fixed::operator>( const Fixed &num ) const
{
    return this->getRawBits() > num.getRawBits();
}

bool    Fixed::operator>=( const Fixed &num ) const
{
    return this->getRawBits() >= num.getRawBits();
}

bool    Fixed::operator<( const Fixed &num ) const
{
    return this->getRawBits() < num.getRawBits();
}

bool    Fixed::operator<=( const Fixed &num ) const
{
    return this->getRawBits() <= num.getRawBits();
}

bool    Fixed::operator==( const Fixed &num ) const
{
    return this->getRawBits() == num.getRawBits();
}

bool    Fixed::operator!=( const Fixed &num ) const
{
    return this->getRawBits() != num.getRawBits();
}

Fixed Fixed::operator+( const Fixed &other ) const
{
    return Fixed( this->toFloat() + other.toFloat() );
}

Fixed Fixed::operator*( const Fixed &other ) const
{
    return Fixed( this->toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( const Fixed &other ) const
{
    return Fixed( this->toFloat() / other.toFloat() );
}

Fixed Fixed::operator-( const Fixed &other ) const
{
    return Fixed( this->toFloat() - other.toFloat() );
}

Fixed& Fixed::operator++( void )
{
    ++this->_number;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed temp(*this);
    temp._number = this->_number++;
    return temp;
}

Fixed& Fixed::operator--( void )
{
    --this->_number;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed temp(*this);
    temp._number = this->_number--;
    return temp;
}

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_number;
	static const int _num_bit = 8;

public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=( const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
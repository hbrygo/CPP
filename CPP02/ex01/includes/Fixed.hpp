#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int	_number;
	static const int _num_bit = 8;

public:
    Fixed( void );
    Fixed( const int num );
    Fixed( const float num );
    Fixed( const Fixed &other );
    ~Fixed();
    Fixed &operator( const Fixed &other );
    int getRawBits( void ) const;
	void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

#endif
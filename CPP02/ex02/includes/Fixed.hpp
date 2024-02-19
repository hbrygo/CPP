#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int	                _number;
	static const int    _num_bit = 8;

public:
    Fixed( void );
    Fixed( const int num );
    Fixed( const float num );
    Fixed( const Fixed &other );
    ~Fixed();
    int getRawBits( void ) const;
	void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(Fixed const &a, Fixed const &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(Fixed const &a, Fixed const &b);

    Fixed&  operator=( const Fixed &other );
    bool    operator>( const Fixed &num ) const;
    bool    operator>=( const Fixed &num ) const;
    bool    operator<( const Fixed &num ) const;
    bool    operator<=( const Fixed &num ) const;
    bool    operator==( const Fixed &num ) const;
    bool    operator!=( const Fixed &num ) const;

    Fixed operator+( const Fixed &other ) const;
    Fixed operator*( const Fixed &other ) const;
    Fixed operator/( const Fixed &other ) const;
    Fixed operator-( const Fixed &other ) const;

    Fixed& operator++( void );
    Fixed operator++( int );
    Fixed& operator--( void );
    Fixed operator--( int );

};

std::ostream& operator<<(std::ostream& f, Fixed const& i);

#endif
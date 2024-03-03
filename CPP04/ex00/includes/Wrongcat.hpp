#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal{
	private:

	public:
		WrongCat( void );
		WrongCat( const WrongCat& other );
		~WrongCat();
		WrongCat& operator=( const WrongCat& other );
		virtual void makeSoung( void ) const;
};

#endif
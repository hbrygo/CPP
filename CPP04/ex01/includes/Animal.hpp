#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal{
	protected:
		std::string _type;

	public:
		Animal( void );
		Animal( const Animal& other );
		virtual ~Animal();
		Animal& operator=( const Animal& other );

		std::string getType( void ) const;
		virtual void makeSound( void ) const;
		virtual Brain* getBrain() const;
};

#endif
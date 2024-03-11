#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal{
	protected:
		std::string _type;
		Brain* _brain;
	public:
		Animal( void );
		virtual ~Animal();
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );
		std::string getType( void ) const;
		virtual void makeSound( void ) const = 0;
};

#endif
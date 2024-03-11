#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	private:

	public:
		Dog( void );
		Dog( const Dog &other );
		~Dog();
		Dog& operator=( const Dog &other );
		virtual void makeSound( void ) const;
};

#endif
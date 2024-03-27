#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* _brain;
	public:
		Cat( void );
		Cat( const Cat& other );
		~Cat();
		Cat& operator=( const Cat& other);
		void makeSound( void ) const;

		virtual Brain* getBrain() const;
};

#endif
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Wrongcat.hpp"
#include <iostream>


int	main( void ) {
	// AAnimal	chimera;	//this won't work because abstract
	const Animal	*(animals[4]) = {new Dog(), new Cat(), new Cat(), new Dog()};
	std::cout << std::endl;
	Brain			*brain;

	brain = animals[1]->getBrain();
	// brain = NULL;
	if (brain) {
		brain->addIdea( "Pass this cpp." );
		brain->addIdea( "Lick my paw." );
		brain->setIdea( 3, "Learn some kung fu." );
	}

	Animal	*copycat = new Cat(*(Cat *)(animals[1]));

	if (brain) {
		brain->addIdea( "yoghurt." );
	}
	brain = copycat->getBrain();
	if (brain) {
		brain->addIdea( "cereals." );
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; ++i) {
		brain = animals[1]->getBrain();
		if (brain) {
			std::cout << i << " original : " << brain->getIdea( i ) << std::endl;
		} else {
			std::cout << "Error, brain not found." << std::endl;
		}
		brain = copycat->getBrain();
		if (brain) {
			std::cout << "      copy : " << brain->getIdea( i ) << std::endl;
		} else {
			std::cout << "Error, brain not found." << std::endl;
		}
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	std::cout << std::endl;
	delete copycat;
	return (0);
}
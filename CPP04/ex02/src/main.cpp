#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Wrongcat.hpp"
#include <iostream>

int	main( void ) {
	// const Animal* meta = new Animal(); //don't work here
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;
	std::cout << "*************Call type**************" << std::endl;
	// std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl;
	std::cout << "*************Call sound*************" << std::endl;
	// meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	k->makeSound();

	std::cout << std::endl;
	std::cout << "*************Delete all*************" << std::endl;
	// delete meta;
	delete i;
	delete j;
	delete k;
	std::cout << std::endl;

	// const Animal	*lucy = new Animal(); //don't work here
	// const Animal	*og = new Dog(*(Dog *)lucy);
	// const Animal	*cpy = new Dog(*(Dog *)og);
	// const Animal	*cpyter = new Animal(*og); //don't work here
	// const Animal	*cpydog = new Animal(*(Dog *)og); //don't work here
	// const Animal	*cpycat = new Animal(*(Cat *)og);//don't work here
	// const Animal	*catcpy = new Cat(*(Cat *)og);
	// const Animal	*catfail = new Cat(*og); //this doesn't work

	std::cout << std::endl;
	// std::cout << lucy->getType() << " lucy -> ";
	// lucy->makeSound();
	// std::cout << og->getType() << " og -> ";
	// og->makeSound();
	// std::cout  << cpy->getType() << " cpy -> ";
	// cpy->makeSound();
	// std::cout  << cpyter->getType() << " cpyter -> ";
	// cpyter->makeSound();
	// std::cout  << cpydog->getType() << " cpydog -> ";
	// cpydog->makeSound();
	// std::cout  << cpycat->getType() << " cpycat -> ";
	// cpycat->makeSound();
	// std::cout  << catcpy->getType() << " catcpy -> ";
	// catcpy->makeSound();
	std::cout << std::endl;
	
	// delete lucy;
	// delete og;
	// delete cpy;
	// delete cpyter;
	// delete cpydog;
	// delete cpycat;
	// delete catcpy;
	return (0);
}
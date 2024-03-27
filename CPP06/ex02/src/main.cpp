#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void){
    int random_number = 1 + std::rand() % (3);
    std::cout << "random_number: " << random_number << std::endl;
    switch(random_number){
        case 1:
            return new A();
        case 2:
            return new B();
        case 3:
            return new C();
    }
    return 0;
}

void identify(Base* p){
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);

    if (a)
        std::cout << "A" << std::endl;
    else if (b)
        std::cout << "B" << std::endl;
    else if (c)
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        B& a = dynamic_cast<B&>(p);
        (void)a;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        C& a = dynamic_cast<C&>(p);
        (void)a;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e){}
}

int	main( void ) {
    srand(time(NULL));
	Base* first = generate();
	identify(first);
	identify(*first);
	delete first;
	Base* second = generate();
	identify(second);
	identify(*second);
	delete second;
	Base* third = generate();
	identify(third);
	identify(*third);
	delete third;
	return (0);
}
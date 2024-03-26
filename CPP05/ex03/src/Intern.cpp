#include "../includes/Intern.hpp"

Intern::Intern( void ){
    std::cout << "Default constructor Intern called" << std::endl;
}

Intern::Intern( const Intern& other ){
    (void)other;
    return ;
}

Intern::~Intern(){
    std::cout << "Default destructor Intern called" << std::endl;
}

Intern& Intern::operator=( const Intern& other ){
    (void)other;
    return *this;
}

AForm* Intern::makeForm( std::string name, std::string target ){
    std::string form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;

    while (i < 3 && form[i] != name)
        i++;

    switch(i){
        case 0:
            return new ShrubberyCreationForm(target);
            break ;
        case 1:
            return new RobotomyRequestForm(target);
            break ;
        case 2:
            return new PresidentialPardonForm(target);
            break ;
        default:
            throw NotAGoodChoiceExeption();
            break ;
    };
    return NULL;
}

const char* Intern::NotAGoodChoiceExeption::what() const throw(){
    return "You cannot create a form with this name";
}
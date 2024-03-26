#ifndef INTERN_HPP
# define INTERN_HPP

#include <stdexcept>
#include "iostream"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Bureaucrat;
class AForm;

class Intern{
    private:

    public:
        Intern( void );
        Intern( const Intern& other );
        ~Intern();
        Intern& operator=( const Intern& other );

        AForm *makeForm( std::string name, std::string target );

    class NotAGoodChoiceExeption: public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif
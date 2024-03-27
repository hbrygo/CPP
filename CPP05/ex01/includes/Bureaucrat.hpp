#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name );
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat();
		Bureaucrat& operator=( const Bureaucrat& other );

		std::string getName() const;
		int getGrade() const;
		void gradeDown();
		void gradeUp();
		void signForm( Form& f ) const;
		
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {	
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& f, Bureaucrat const& i);

#endif
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSigne;
        const int _gradeToExecute;
    public:
        Form( void );
        Form ( std::string name);
        Form ( std::string name, int grade);
        Form ( std::string name, int gradeToSigne, int gradeToExecute);
        Form ( const Form& other );
        ~Form();
        Form& operator=( const Form& other );
        void beSigned( const Bureaucrat& b );

        bool getSigned( void ) const;
        std::string getName( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExecut( void ) const;

        class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {	
			public:
				virtual const char* what() const throw();
		};

        class AlreadySignedException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& f, Form const& i);

#endif
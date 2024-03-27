#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSigne;
        const int _gradeToExecute;
    public:
        AForm( void );
        AForm ( std::string name);
        AForm ( std::string name, int grade);
        AForm ( std::string name, int gradeToSigne, int gradeToExecute);
        AForm ( const AForm& other );
        virtual ~AForm();
        AForm& operator=( const AForm& other );
        void beSigned( const Bureaucrat& b );

        bool getSigned( void ) const;
        std::string getName( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExecut( void ) const;
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        
        class NotSignedException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& f, AForm const& i);

#endif
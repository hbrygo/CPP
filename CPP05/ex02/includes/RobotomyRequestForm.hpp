#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( const RobotomyRequestForm& other );
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

        void execute(Bureaucrat const & executor) const;
};

#endif
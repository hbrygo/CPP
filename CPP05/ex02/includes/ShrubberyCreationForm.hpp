#ifndef SHRUBBERYCREATION_HPP
# define SHRUBBERYCREATION_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm ( std::string target );
        ShrubberyCreationForm ( const ShrubberyCreationForm& other );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "Default constructor PresidentialPardonForm called" << std::endl;
    this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5) {
    this->_target = target;
    std::cout << this->_target << " has " << this->getName() << " name and need a grade equal or higher than " << this->getGradeToExecut();
    std::cout << " to be execute and higher or equal to " << this->getGradeToSign() << " to be signed." << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm("PresidentialPardonForm", 25, 5) {
    this->_target = other._target;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Default destructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ){
    (void)other;
    return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const{
    if (this->getSigned() == 0)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecut())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned bu Zaphod Beebletrox." << std::endl;
}
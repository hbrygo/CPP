#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "Default constructor PresidentialPardonForm called" << std::endl;
    this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5) {
    this->_target = target;
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
    if (this->_isSigned == 0)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned bu Zaphod Beebletrox." << std::endl;
}
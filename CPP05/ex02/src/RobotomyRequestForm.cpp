#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "Default constructor RobotomyRequestForm called" << std::endl;
    this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45) {
    this->_target = target;
    std::cout << this->_target << " has " << this->_name << " name and need a grade equal or higher than " << this->_gradeToExecute;
    std::cout << " to be execute and higher or equal to " << this->_gradeToSigne << " to be signed." << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm("RobotomyRequestForm", 72, 45) {
    this->_target = other._target;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Default destructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ){
    (void)other;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (this->_isSigned == 0)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    std::cout << "Drill drill drill" << std::endl;
    srand((unsigned int) time(NULL));
    int randomNumber = rand();
    if (randomNumber % 2 == 0)
        std::cout << "Then, informs that " << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}
#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"){
	std::cout << "Default constructor bureaucrat called" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat( const std::string name ) : _name(name){
	std::cout << "Default constructor bureaucrat called" << std::endl;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name){
	std::cout << "Default constructor bureaucrat called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ){
	*this = other;
	return ;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Default destructor bureaucrat called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ){
	this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::gradeDown(){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << this->_name << " grade down" << std::endl;
}

void Bureaucrat::gradeUp(){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << " grade up" << std::endl;
}

void Bureaucrat::signForm( AForm& f ) const{
	if (f.getSigned() == 1)
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << f.getName() << " because he has aqua poney." << std::endl;
}

void Bureaucrat::executeForm( AForm const & form ){
	form.execute(*this);
	std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
}

std::ostream& operator<<(std::ostream& f, Bureaucrat const& b)
{
    f << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return f;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Error: your grade is too High for this action.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Error: your grade is too low for this action";
}
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
	std::cout << this->_name << " grade down from " << this->_grade - 1 << " to " << this->_grade << std::endl;
}

void Bureaucrat::gradeUp(){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << " grade up from " << this->_grade + 1 << " to " << this->_grade << std::endl;
}

void Bureaucrat::signForm( AForm& f ) const{
	try {
		f.beSigned( *this );
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form ){
	try {
		form.execute(*this);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
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
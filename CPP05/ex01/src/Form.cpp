#include "../includes/Form.hpp"

Form::Form( void ) : _name("Default"), _gradeToSigne(150), _gradeToExecute(150) {
    std::cout << "Default constructor Form called" << std::endl;
    this->_isSigned = 0;
}

Form::Form ( std::string name) : _name(name), _gradeToSigne(150), _gradeToExecute(150) {
    this->_isSigned = 0;
}

Form::Form ( std::string name, int grade) :_name(name), _gradeToSigne(grade), _gradeToExecute(150) {
    this->_isSigned = 0;
    if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw Form::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw Form::GradeTooLowException();
}

Form::Form ( std::string name, int gradeToSigne, int gradeToExecute) :_name(name), _gradeToSigne(gradeToSigne), _gradeToExecute(gradeToExecute) {
    this->_isSigned = 0;
    if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw Form::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw Form::GradeTooLowException();
}

Form::Form ( const Form& other ) : _name(other._name), _gradeToSigne(other._gradeToSigne), _gradeToExecute(other._gradeToExecute) {
    this->_isSigned = other._isSigned;
    return ;
}

Form::~Form(){
    std::cout << "Defauld destructor " << std::endl;
}

bool Form::getSigned( void ) const{
    return this->_isSigned;
}

std::string Form::getName( void ) const{
    return this->_name;
}

int Form::getGradeToSign( void ) const{
    return this->_gradeToSigne;
}

int Form::getGradeToExecut( void ) const{
    return this->_gradeToExecute;
}


Form& Form::operator=( const Form& other ){
    this->_isSigned = other._isSigned;
    return *this;
}

void Form::beSigned( Bureaucrat b ){
    if (this->_gradeToSigne > b.getGrade())
        throw Form::GradeTooLowException();
    if (this->_isSigned == 1)
        throw Form::AlreadySignedException();
    this->_isSigned = 1;
    std::cout << "Form has been signed." << std::endl;
}

std::ostream& operator<<(std::ostream& f, Form const& i){
    f << "Form: " << i.getName();
    if (i.getSigned() == 0)
        f << " is not signed.";
    else
        f << "is signed.";
    f << " The grade needed to be at: " << i.getGradeToSign() << " to sign." << std::endl;
    return f;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Error: your grade is too High for this action.";
}

const char* Form::AlreadySignedException::what() const throw(){
	return "Form already signed.";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Error: your grade is too low for this action";
}
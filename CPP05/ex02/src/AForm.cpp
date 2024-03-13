#include "../includes/AForm.hpp"

AForm::AForm( void ) : _name("Default"), _gradeToSigne(150), _gradeToExecute(150) {
    std::cout << "Default constructor AForm called" << std::endl;
    this->_isSigned = 0;
}

AForm::AForm ( std::string name) : _name(name), _gradeToSigne(150), _gradeToExecute(150) {
    this->_isSigned = 0;
}

AForm::AForm ( std::string name, int grade) :_name(name), _gradeToSigne(grade), _gradeToExecute(150) {
    this->_isSigned = 0;
    if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw AForm::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm ( std::string name, int gradeToSigne, int gradeToExecute) :_name(name), _gradeToSigne(gradeToSigne), _gradeToExecute(gradeToExecute) {
    this->_isSigned = 0;
    if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw AForm::GradeTooHighException();
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm ( const AForm& other ) : _name(other._name), _gradeToSigne(other._gradeToSigne), _gradeToExecute(other._gradeToExecute) {
    this->_isSigned = other._isSigned;
    return ;
}

AForm::~AForm(){
    std::cout << "Defauld destructor " << std::endl;
}

bool AForm::getSigned( void ) const{
    return this->_isSigned;
}

std::string AForm::getName( void ) const{
    return this->_name;
}

int AForm::getGradeToSign( void ) const{
    return this->_gradeToSigne;
}

int AForm::getGradeToExecut( void ) const{
    return this->_gradeToExecute;
}


AForm& AForm::operator=( const AForm& other ){
    this->_isSigned = other._isSigned;
    return *this;
}

void AForm::beSigned( Bureaucrat b ){
    if (this->_gradeToSigne > b.getGrade())
        throw AForm::GradeTooLowException();
    if (this->_isSigned == 1)
        throw AForm::AlreadySignedException();
    this->_isSigned = 1;
    std::cout << "Form has been signed." << std::endl;
}

std::ostream& operator<<(std::ostream& f, AForm const& i){
    f << "Form: " << i.getName();
    if (i.getSigned() == 0)
        f << " is not signed.";
    else
        f << "is signed.";
    f << " The grade needed to be at: " << i.getGradeToSign() << " to sign." << std::endl;
    return f;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Error: your grade is too High for this action.";
}

const char* AForm::AlreadySignedException::what() const throw(){
	return "Form already signed.";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Error: your grade is too low for this action";
}
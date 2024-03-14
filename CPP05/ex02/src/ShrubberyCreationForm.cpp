#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "ShrubberyCreationForm", 145, 137) {
    std::cout << "Default constructor Shrubbery called" << std::endl;
    this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string target ) : AForm("ShrubberyCreationForm", 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm& other ) : AForm("ShrubberyCreationForm", 145, 137) {
    this->_target = other._target;
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ){
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Default destructor Shrubbery called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    if (this->_isSigned == 0)
        throw AForm::NotSignedException();
    if (executor.getGrade() < this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    std::ofstream file(this->_target + "_shrubbery");
    if (file.is_open()){
        file << "                       O                         " << std::endl;
        file << "                      ***                        " << std::endl;
        file << "                     **O**                       " << std::endl;
        file << "                    *******                      " << std::endl;
        file << "                   *********                     " << std::endl;
        file << "                  ***********                    " << std::endl;
        file << "                   ******o**                     " << std::endl;
        file << "                  ***********                    " << std::endl;
        file << "                 ****o********                   " << std::endl;
        file << "                ***************                  " << std::endl;
        file << "               ****o***o********                 " << std::endl;
        file << "              *******************                " << std::endl;
        file << "            ***********************              " << std::endl;
        file << "               *****O***********                 " << std::endl;
        file << "              **********o********                " << std::endl;
        file << "             ****************o****               " << std::endl;
        file << "            **O********************              " << std::endl;
        file << "           ***********o********O****             " << std::endl;
        file << "         *****************************           " << std::endl;
        file << "             *********************               " << std::endl;
        file << "            ***o*******************              " << std::endl;
        file << "           ***********o*******o*****             " << std::endl;
        file << "          ***************************            " << std::endl;
        file << "         ***********************O*****           " << std::endl;
        file << "        ***O***************************          " << std::endl;
        file << "      ***********************************        " << std::endl;
        file << "           *************************             " << std::endl;
        file << "          *******o********o**********            " << std::endl;
        file << "         *****************************           " << std::endl;
        file << "        **************o****************          " << std::endl;
        file << "       *************************O*******         " << std::endl;
        file << "      *****O*****************************        " << std::endl;
        file << "    **************o************************      " << std::endl;
        file << "          ***************************            " << std::endl;
        file << "         *************o***************           " << std::endl;
        file << "        ***********o*******************          " << std::endl;
        file << "       **************************O******         " << std::endl;
        file << "      ***o******************O************        " << std::endl;
        file << "    ***o***********o****************o******      " << std::endl;
        file << "                      ###                        " << std::endl;
        file << "                      ###                        " << std::endl;
        file << "                      ###                        " << std::endl;
        file << "                  ###########                    " << std::endl;
        file << "                  ###########                    " << std::endl;
        file.close();
    }
    else
        std::cout << "File error" << std::endl;
}
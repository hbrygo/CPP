#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "Default", 145, 137) {
    std::cout << "Default constructor Shrubbery called" << std::endl;
    this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string target ) : AForm("Default", 145, 137) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm& other ) : AForm("Default", 145, 137) {
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
    std::ofstream file(this->_target + "_shrubbery");
    if (file.is_open()){
        file << "
                       O                         
                      ***                        
                     **O**                       
                    *******                      
                   *********                     
                  ***********                   
                   ******o**                     
                  ***********                    
                 ****o********                   
                ***************                  
               ****o***o********                 
              *******************                
            ***********************              
               *****O***********                 
              **********o********                
             ****************o****               
            **O********************              
           ***********o********O****             
         *****************************           
             *********************               
            ***o*******************              
           ***********o*******o*****             
          ***************************            
         ***********************O*****           
        ***O***************************          
      ***********************************        
           *************************             
          *******o********o**********            
         *****************************           
        **************o****************          
       *************************O*******         
      *****O*****************************        
    **************o************************      
          ***************************            
         *************o***************           
        ***********o*******************          
       **************************O******         
      ***o******************O************        
    ***o***********o****************o******      
                      ###                        
                      ###                        
                      ###                        
                  ###########                    
                  ###########                    " << std::endl;
    }
}
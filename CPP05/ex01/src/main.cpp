#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main( void ) {
	Bureaucrat	master( "john", 46 );
	Bureaucrat	servant( "marc", 47 );
	std::cout << std::endl;

	try {
		std::cout << "********** TRY 0 **********" << std::endl << std::endl;
		Form		form( "random request", 48, 4 );

		std::cout << std::endl;
		std::cout << master << std::endl;
		std::cout << servant << std::endl;
		std::cout << form << std::endl << std::endl;

		servant.signForm(form);
		master.signForm(form);
		servant.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}

	try {
		std::cout << "********** TRY 1 **********" << std::endl << std::endl;
		Form		form( "random request", 0, 4 );

		std::cout << std::endl;
		std::cout << master << std::endl;
		std::cout << servant << std::endl;
		std::cout << form << std::endl << std::endl;

		master.signForm(form);
		servant.signForm(form);
		servant.gradeDown();
		servant.signForm(form);
		std::cout << std::endl << "********** SUCCESS **********" << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}
	return (0);
}
#include "../includes/Span.hpp"

int main()
{
    try {
        Span sp = Span(15);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        sp.fillSpan(array, array + 10);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
		std::cout << std::endl << "********** CATCH **********" << std::endl;
		std::cout << std::endl << e.what() << std::endl << std::endl;
	}
    return 0;
}
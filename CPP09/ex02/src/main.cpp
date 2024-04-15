#include "../includes/PmergeMe.hpp"

int createVector(int argc, char **argv, std::vector<int> &valueToSort){
    for (int i = 1; i < argc; i++){
        valueToSort.push_back(atoi(argv[i]));
    }
    return 0;
}

int checkArg(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        std::string str = argv[i];
        if (str.find_first_not_of("0123456789-") != std::string::npos) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv){
    if (argc == 1){
        std::cout << "Error: enter some argument" << std::endl;
        return 1;
    }
    if (checkArg(argc, argv) == 1){
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }
    std::vector<int> valueToSort;
    if (createVector(argc, argv, valueToSort) == 1){
        std::cout << "Error in creation map" << std::endl;
        return 1;
    }
    std::vector<int>::iterator it = valueToSort.begin();
	std::vector<int>::iterator ite = valueToSort.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
    return 0;
}
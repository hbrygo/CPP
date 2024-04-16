#include "../includes/PmergeMe.hpp"

template<typename T>
int createStack(int argc, char **argv, T &valueToSort){
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
		int	neg = 0;
		for (int j = 0; argv[i][j]; j++){
			if (argv[i][j] == '-')
				neg++;
		}
		if (neg > 1)
			return 1;
    }
    return 0;
}

template<typename T>
void display(T valueToSort, std::string str){
    typename T::iterator it = valueToSort.begin();
    typename T::iterator ite = valueToSort.end();
	std::cout << str << ": ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void mergeAndSort(T begin, T middle, T end) {
	typedef typename std::iterator_traits<T>::value_type ValueType;
	std::vector<ValueType> stack1(begin, middle);
	std::vector<ValueType> stack2(middle, end);

	typename std::vector<ValueType>::iterator stack1Itter = stack1.begin();
    typename std::vector<ValueType>::iterator stack2Itter = stack2.begin();
	T target = begin;
	while (stack1Itter != stack1.end() && stack2Itter != stack2.end()){
		if (*stack1Itter <= *stack2Itter){
			*target = *stack1Itter;
			stack1Itter++;
		}
		else{
			*target = *stack2Itter;
			stack2Itter++;
		}
		target++;
	}
	for (; stack1Itter != stack1.end(); ++stack1Itter){
		*target = *stack1Itter;
		target++;
	}
	for (; stack2Itter != stack2.end(); ++stack2Itter){
		*target = *stack2Itter;
		target++;
	}
}

template<typename T>
void sort(T& begin, T& end){
	/*
	* ::difference_type est un membre de la classe std::iterator_traits.
	* Il est utilisé pour définir le type entier qui représente la différence entre deux itérateurs.
	* En d'autres termes, ::difference_type est le type utilisé pour stocker la distance entre deux itérateurs.
	*/
	// en gros iterator_traits et difference_type sont la pour avoir des infos en plus a partir de begin et end
	typename std::iterator_traits<T>::difference_type length = std::distance(begin, end);
    if (length > 1) {
        T middle = std::next(begin, length / 2);
        sort(begin, middle);
        sort(middle, end);
        mergeAndSort(begin, middle, end);
    }
}

template<typename T>
void algo(T& valueToSort){
	sort(valueToSort.begin(), valueToSort.end());
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
    std::vector<int> valueVector;
    std::deque<int> valueDeque;
    if (createStack(argc, argv, valueVector) == 1){
        std::cout << "Error in creation map" << std::endl;
        return 1;
    }
    if (createStack(argc, argv, valueDeque) == 1){
        std::cout << "Error in creation map" << std::endl;
        return 1;
    }
	{
		std::clock_t start = std::clock();
		display(valueVector, "Before sort");
		algo(valueVector);
		display(valueVector, "After sort");
		std::clock_t end = std::clock();
		double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector :" << elapsed_time << " microsecondes" << std::endl;
	}
	{
		std::clock_t start = std::clock();
		// display(valueDeque, "Before sort");
		algo(valueDeque);
		// display(valueDeque, "After sort");
		std::clock_t end = std::clock();
		double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :" << elapsed_time << " microsecondes" << std::endl;
	}
    return 0;
}
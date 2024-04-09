#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <vector>

class occurenceNotFound: public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: out of the array";
        }
};

template<typename T>
int easyfind( T valueT, int valueInt ) {
    typename T::iterator it = std::find (valueT.begin(), valueT.end(), valueInt);
    if (it == valueT.end())
        throw occurenceNotFound();
    return std::distance(valueT.begin(), it);
}

#endif
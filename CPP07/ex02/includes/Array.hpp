#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
    private:
        T* _array;
        unsigned int _n;

    public:
        Array<T> ( void ) {
            this->_array = new T[0];
            this->_n = 0;
        }
        Array<T> ( unsigned int n ) {
            this->_array = new T[n];
            for (unsigned int i = 0; i < n; i++) {
                this->_array[i] = 0;
            }
            this->_n = n;
            return ;
        }
        Array<T> ( const Array& other ) {
            this->_array = new T[other._n];
            for (unsigned int i = 0; i < other._n; i++) {
                this->_array[i] = other._array[i];
            }
            this->_n = other._n;
            return ;
        }
        ~Array<T> () {
            delete[] this->_array;
        }
        T& operator[]( unsigned int i ) {
            if (i < 0 || i > this->_n )
                throw Array::OutOfTheArray();
            return this->_array[i];
        }
        int size() {
            return this->_n;
        }

        class OutOfTheArray: public std::exception {
			public:
				virtual const char* what() const throw() {
                    return "Error: out of the array";
                }
		};
};

#endif
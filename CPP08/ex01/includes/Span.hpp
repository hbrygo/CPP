#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <exception>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _number;

    public:
        Span( unsigned int n );
        Span( const Span& other );
        ~Span();
        Span& operator=( const Span& other );

        void addNumber( int num );
        void display();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        template <typename InputIterator>
        void fillSpan(InputIterator begin, InputIterator end){
            for (InputIterator it = begin; it != end; ++it) {
                if (this->_number.size() >= this->_n)
                    throw std::length_error("To many element for add a new value");
                this->_number.push_back(*it);
            }
        }
};

std::ostream& operator<<(std::ostream& f, Span& s);

#endif
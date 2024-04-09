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
        int shortestSpan();
        int longestSpan();
};

std::ostream& operator<<(std::ostream& f, Span& s);

#endif
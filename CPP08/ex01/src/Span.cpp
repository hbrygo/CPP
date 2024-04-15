#include "../includes/Span.hpp"

Span::Span( unsigned int n ){
    std::cout << "Constructor called" << std::endl;
    this->_n = n;
}

Span::Span( const Span& other ) : _n(other._n), _number(other._number) {
    return ;
}

Span::~Span(){
    std::cout << "Destructor called" << std::endl;
}

Span& Span::operator=( const Span& other ){
    this->_n = other._n;
    this->_number = other._number;
    return *this;
}

void Span::addNumber( int num ){
    if (this->_number.size() >= this->_n)
        throw std::length_error("To many element for add a new value");
    this->_number.push_back(num);
}

void Span::display(){
    std::cout << "Max size: " << this->_n << std::endl;
    std::cout << "Content: " << std::endl;
    for (size_t i = 0; i < this->_number.size(); i++){
        std::cout << i + 1 << ": " << this->_number[i] << std::endl;
    }
}

unsigned int Span::shortestSpan(){
    if (this->_number.size() <= 1)
        throw std::logic_error("Not enough value to calculate a size");
    std::vector<int> range;
    for (size_t i = 0; i < this->_number.size(); i++){
        for (size_t j = i + 1; j < this->_number.size(); j++){
            if (this->_number[i] < this->_number[j]) {
                range.push_back(this->_number[j] - this->_number[i]);
            }
            else {
                range.push_back(this->_number[i] - this->_number[j]);
            }
        }
    }
    return *std::min_element(range.begin(), range.end());
}

unsigned int Span::longestSpan(){
    if (this->_number.size() <= 1)
        throw std::logic_error("Not enough value to calculate a size");
    std::vector<int> range;
    for (size_t i = 0; i < this->_number.size(); i++){
        for (size_t j = i + 1; j < this->_number.size(); j++){
            if (this->_number[i] < this->_number[j]) {
                range.push_back(this->_number[j] - this->_number[i]);
            }
            else {
                range.push_back(this->_number[i] - this->_number[j]);
            }
        }
    }
    return *std::max_element(range.begin(), range.end());
}

std::ostream& operator<<(std::ostream& f, Span& s)
{
    s.display();
    return f;
}
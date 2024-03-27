#include "../includes/Serializer.hpp"

Serializer::Serializer( void ){
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer( const Serializer& other ){
    *this = other;
    return ;
}

Serializer::~Serializer(){
    std::cout << "Default destructor called" << std::endl;
}

Serializer& Serializer::operator=( const Serializer& other ){
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
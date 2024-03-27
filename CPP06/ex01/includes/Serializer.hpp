#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer {
    private:

    public:
        Serializer( void );
        Serializer( const Serializer& other );
        ~Serializer();
        Serializer& operator=( const Serializer& other );

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
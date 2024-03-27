#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
    private:
        std::string _ideas[100];
        int _newIdea;
    public:
        Brain( void );
        Brain( const Brain& other );
        ~Brain();
        Brain& operator=(const Brain& other );

        std::string getIdea( int i );
        void addIdea( const std::string idea );
        void setIdea( int i, const std::string idea );
};

#endif
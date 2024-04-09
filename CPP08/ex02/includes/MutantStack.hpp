#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {
    private:
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack( void ) : std::stack<T>() {}
        MutantStack( const MutantStack& other ) : std::stack<T>(other) {}
        ~MutantStack() {}
        MutantStack& operator=( const MutantStack& other ) {
            std::stack<T>::operator=(other);
            return *this;
        }

        // ici c vient de la classe(container) std::stack c'est pour cela qu'on ne doit pas le creer dans la classe mutant ou dans le main.
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
};

#endif
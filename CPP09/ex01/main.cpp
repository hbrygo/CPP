#include <stack>
#include <iostream>
#include <string>

int execute(char **argv);

int main (int argc, char **argv){
    if (argc != 2) {
        std::cout << "Error: only one argument require (ex: \"0 2 - 6 + 6 9 - *\")" << std::endl;
        return 1;
    }
    if (execute(argv) == 1)
        return 1;
    return 0;
}
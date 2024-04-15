#include <stack>
#include <iostream>

int execute(char *argv){
    std::stack<int> value;
    for (int i = 0; argv[i]; i++){
        int sign = 1;
        if (argv[i] == ' ')
            i++;
        if (argv[i] == '-' && argv[i + 1] && argv[i + 1] <= '9' && argv[i + 1] >= '0'){
            sign = -1;
            i++;
        }
        if (argv[i] >= '0' && argv[i] <= '9')
            value.push((argv[i] - '0') * sign);
        else if (argv[i] == '*' || argv[i] == '-' || argv[i] == '+' || argv[i] == '/') {
            if (value.size() < 2) {
                std::cout << "Error" << std::endl;
                return 1;
            }
            char op = argv[i];
            int value2 = value.top();
            value.pop();
            int value1 = value.top();
            value.pop();
            switch (op){
                case '+':
                    value.push(value1 + value2);
                    break ;
                case '-':
                    value.push(value1 - value2);
                    break ;
                case '*':
                    value.push(value1 * value2);
                    break ;
                case '/':
                    if (value2 == 0) {
                        std::cout << "Error: can't divide by 0" << std::endl;
                        return 1;
                    }
                    value.push(value1 / value2);
                    break ;
                default:
                    std::cout << "unknown operator" << std::endl;
                    return 1;
            }
        } else {
            std::cout << "Error: input" << std::endl;
            return 1;
        }
    }
    std::cout << value.top() << std::endl;
    return 0;
}
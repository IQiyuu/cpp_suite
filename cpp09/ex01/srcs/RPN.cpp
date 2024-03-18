#include "RPN.hpp"

RPN::RPN( void ) {
    std::cout << "RPN \033[32mcreated\033[0m" << std::endl;
}

RPN::RPN( const RPN &ref ) {
    std::cout << "RPN \033[32mcreated\033[0m" << std::endl;
    *this = ref;
}

RPN &RPN::operator=( const RPN &ref ) {
    std::cout << "RPN \033[32mcreated\033[0m" << std::endl;
    this->num = ref.num;
    return *this;
}

RPN::~RPN( void ) {
    std::cout << "RPN \033[31mdeleted\033[0m" << std::endl;
}

void RPN::calcul( std::string exp ) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == ' ')
			continue;
        if (std::isdigit(exp[i]))
            this->num.push(exp[i] - '0');
        else if (this->num.size() != 2) {
            std::cout << "Error" << std::endl;
            return ;
        }
        else {
            int tmp = this->num.top();
            this->num.pop();
            switch (exp[i]) {
                case '+':
                    tmp = this->num.top() + tmp;
                    break ;
                case '-':
                    tmp = this->num.top() - tmp;
                    break ;
                case '*':
                    tmp = this->num.top() * tmp;
                    break ;
                case '/':
                    tmp = this->num.top() / tmp;
                    break ;
                default:
                    std::cout << "Error" << std::endl;
                    break ;
            }
            this->num.pop();
            this->num.push(tmp);
        }
    }
    std::cout << this->num.top() << std::endl;
}
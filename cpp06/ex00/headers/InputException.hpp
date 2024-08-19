#ifndef INPUTEXCEPTION
#define INPUTEXCEPTION

#include <iostream>

class InputException : public std::exception {
    private:
        std::string _msg;
            
    public: 
        InputException(const std::string &t);
        const char *what() const throw();
};

#endif
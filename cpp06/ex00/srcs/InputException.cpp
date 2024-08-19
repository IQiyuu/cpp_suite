#include "InputException.hpp"

InputException::InputException( const std::string &msg ): _msg(msg) {}

const char  *InputException::what() const throw() {
    return this->_msg.c_str();
}
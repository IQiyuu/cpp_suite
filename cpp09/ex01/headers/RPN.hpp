#ifndef RPN_HPP
#define RPN_HPP
#pragma once

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<double> num;
    public:
        RPN( void );
        RPN( const RPN & );
        ~RPN();
        RPN &operator=( const RPN & );
        void calcul( std::string );
		
};

#endif
#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << std::endl;
        std::cout << "std::list" << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        std::cout << *it << std::endl;
        ++it;
        std::cout << "apres incrementation (it++) " << *it << std::endl;
        --it;
        std::cout << "apres decrementation (it--) " << *it << std::endl;
        while (it != ite)
        {
            std::cout << *it << "-";
            ++it;
        }
        std::cout << std::endl;
    }
    {
        std::cout << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        std::cout << *it << std::endl;
        ++it;
        std::cout << "apres incrementation (it++) " << *it << std::endl;
        --it;
        std::cout << "apres decrementation (it--) " << *it << std::endl;
        while (it != ite)
        {
            std::cout << *it << "-";
            ++it;
        }
        std::cout << std::endl;
    }
    return 0;
}
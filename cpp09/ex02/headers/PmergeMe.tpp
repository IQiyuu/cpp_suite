#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::displayContainer( T &seq ) {
    typename T::iterator it;
    size_t cpt = 0;

    for (it = seq.begin(); it != seq.end(); it++) {
        if (seq.size() > 6 && (cpt < 3 || cpt > seq.size() - 4))
            std::cout << *it << " ";
        if (seq.size() > 6 && cpt == 3)
            std::cout << "[...] ";
                cpt++;
    }
}

template <typename T>
T PmergeMe::merge( T &v1, T &v2 ) {
    (void)v2;
    return v1;
}

template <typename T>
T PmergeMe::sort( T &vect ) {
    if (vect.size() <= 1)
        return vect;

    typename T::iterator mid = vect.begin();
    std::advance(mid, vect.size() / 2);
    T lHalf(vect.begin(), mid);
    T rHalf(mid, vect.end());


    lHalf = sort(lHalf);
    rHalf = sort(rHalf);

    return merge(lHalf, rHalf);
}
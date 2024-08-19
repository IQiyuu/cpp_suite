#include "PmergeMe.hpp"

template <typename T>
void PmergeMe::displayContainer( T &seq ) {
    typename T::iterator it;
    size_t cpt = 0;

    for (it = seq.begin(); it != seq.end(); it++) {
        if ((seq.size() > 6 && (cpt < 3 || cpt > seq.size() - 4)) || seq.size() <= 6)
            std::cout << *it << " ";
        else if (seq.size() > 6 && cpt == 3)
            std::cout << "[...] ";
                cpt++;
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::merge( T &res, const typename T::value_type &element ) {
    typename T::iterator it = std::lower_bound(res.begin(), res.end(), element);
    res.insert(it, element);
}

template <typename T>
T   PmergeMe::sort( T &data ) {
    if (data.size() <= 1)
        return data;

    T   res;

    typename T::iterator it = data.begin();
    typename T::iterator it_next = it;
    std::advance(it_next, 1);

    if (*it < *it_next) {
        res.push_back(*it);
        res.push_back(*it_next);
    } else {
        res.push_back(*it_next);
        res.push_back(*it);
    }

    it = it_next;
    std::advance(it, 1);

    for (; it != data.end(); ++it)
        merge(res, *it);

    return res;
}
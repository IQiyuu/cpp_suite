#ifndef ITER
#define ITER

#include <iostream>
#include <cctype>

template<typename T>
void    iter(T *arr, size_t size, void (*f)(T &)) {
    if (!arr || !f)
        return ;
    for (size_t i = 0; i < size; i++) 
        f(arr[i]);
}

#endif
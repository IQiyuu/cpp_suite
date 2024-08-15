#include "Serializer.hpp"
#include <iostream>

int main( int, char ** ) {
    Data    d;
    d.i = 0;
    uintptr_t ser = Serializer::serialize(&d);
    std::cout << "ptr de la struct: " << &d << "\nint stocked: " << d.i << std::endl;
    std::cout << "Serialized: " << ser << std::endl;
    Data    *d2 = Serializer::deserialize(ser);
    std::cout << "ptr de la struct deserialized: " << d2 << "\nint stocked: " << d2->i << std::endl;
}
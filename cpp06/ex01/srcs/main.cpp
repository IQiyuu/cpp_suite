#include "Serializer.hpp"
#include <iostream>

int main( int, char ** ) {
    //Serializer a;
    Data    d;
    d.i = 0;
    d.name = "Robert";
    std::cout << "\nStruct data inialized:\ni    = " << d.i << "\nname = " << d.name << "\nptr  = " << &d << "\n" << std::endl;

    uintptr_t ser = Serializer::serialize(&d);
    std::cout << "Serialized: " << ser << "\n" << std::endl;
    Data    *d2 = Serializer::deserialize(ser);
    std::cout << "\nStruct data :\ni    = " << d2->i << "\nname = " << d2->name << "\nptr  = " << d2 << "\n" << std::endl;
}
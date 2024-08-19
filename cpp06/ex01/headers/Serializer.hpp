#ifndef SERIALIZER
#define SERIALIZER

#include <stdint.h>
#include <iostream>

typedef struct Data {
    int         i;
    std::string name;
} Data;

class Serializer {
    public:
        Serializer( void );
        Serializer( const Serializer & );
        Serializer  &operator=( const Serializer & );
        virtual ~Serializer( void ) = 0;
        static uintptr_t    serialize( Data * );
        static Data         *deserialize( uintptr_t );
};

#endif
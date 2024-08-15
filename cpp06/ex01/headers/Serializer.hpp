#ifndef SERIALIZER
#define SERIALIZER

#include <stdint.h>

typedef struct Data {
    int i;
} Data;

class Serializer {
    public:
        static uintptr_t    serialize( Data * );
        static Data         *deserialize( uintptr_t );
};

#endif
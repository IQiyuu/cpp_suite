#include "Serializer.hpp"

Serializer::Serializer( void ) {}
Serializer::Serializer( const Serializer & ref ) { *this = ref; }
Serializer  &Serializer::operator=( const Serializer & ref ) {
    (void) ref;
    return *this;
}

uintptr_t Serializer::serialize( Data *data ) {
    std::cout << "Serialization of " << data->name << "(" << data << ")" << std::endl;
    return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize( uintptr_t ser ) {
    std::cout << "Deserialization of " << ser << std::endl;
    return (reinterpret_cast<Data *>(ser));
}
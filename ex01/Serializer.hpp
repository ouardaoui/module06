#ifndef SERIALIZER_H
#define SERIALIZER_H

#include<iostream>
#include<cstdint>
#include "Data.h"

class Serializer{
  public : 
    Serializer();
    Serializer(const Serializer &cpy);
    Serializer &operator=(const Serializer &sc);
    ~Serializer();
    static uintptr_t serializer(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif // !SERIALIZATION_H

#include"Serializer.hpp"

Serializer::Serializer()
{

}


Serializer::Serializer(const Serializer &cpy)
{
  *this = cpy;
}

Serializer &Serializer::operator=(const Serializer &sc)
{
  (void)sc;
  return *this;
}

uintptr_t Serializer::serializer(Data *ptr)
{
 uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
  return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}

Serializer::~Serializer()
{
  
}

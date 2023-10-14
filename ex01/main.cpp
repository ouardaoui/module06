#include "Serializer.hpp"

int main()
{
  Data *data = new Data;
  data->str = "hello";
  Data *origin = data;
  uintptr_t raw =  Serializer::serializer(data);
  Data *ptr = Serializer::deserialize(raw); 
  std::cout << ptr << std::endl;
  std::cout << origin << std::endl;
  std::cout << data << std::endl;
  delete data;
}

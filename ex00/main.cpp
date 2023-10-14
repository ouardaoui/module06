#include "ScalarConverter.hpp"

int main(int ac, char  *av[])
{
  if(ac == 2)
  {
    ScalarConverter  cv ; 
  
    ScalarConverter::convert(static_cast<std::string>(av[1]));
  }
}

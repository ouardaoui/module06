#include "ScalarConverter.hpp"

enum Type {
  INT, 
  CHAR, 
  DOUBLE, 
  FLOAT,
  INF,
  INVALIDE,
};

ScalarConverter::ScalarConverter()
{
  std::cout<<"Constructor Called"<<std::endl;
}

ScalarConverter::~ScalarConverter()
{
  std::cout<<"Destructor Called"<<std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
  *this = cpy;
  return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc)
{
  if(this != &sc)
  {
    this->_str = sc._str;
  }
  return *this;
}

int ft_type(std::string str)
{
  if(str == "-inf"  || str == "+inf" || str == "-inff" || str == "+inff")
    return (INF);
  int i = 0;
  if(str.length() == 1 && (str[0] < '0' || str[0] > '9') )
   return (CHAR);
  while(str[i] >= '0' && str[i] <= '9') 
      i++;
  if(str[i] == '\0')
    return (INT);
  if (str[i] == '.')
    i++;
  while(str[i] >= '0' && str[i] <= '9')
    i++;
  if(str[i] == '\0')
    return (DOUBLE);
  else if(str[i] == 'f' && str[i + 1] == '\0')
    return (FLOAT);
  return (INVALIDE);
}

void handle_char(int k)
{
    if(k >= 0 && k <= 32)
      std::cout<<"char : Non displayable\n";
    else if(k > 32 &&  k < 127)
      std::cout<<"char : "<< static_cast<char>(k) <<"\n";
    else
      std::cout<<"char : impossible\n";
}

void ScalarConverter::convert(std::string str)
{

  int type = ft_type(str);
  if(type == CHAR)
  {
    //int k = atoi(str.c_str());
    int k = static_cast<float>(str[0]);
    if(str[0] >= 0 && str[0] <= 32)
      std::cout<<"char : Non displayable\n";
    else 
      std::cout<<"char : "<<str[0]<<"\n";
    std::cout<<"int : "<<k << "\n";
    std::cout<<"float : "<<k<<".0f\n"; 
    std::cout<<"double : "<<k<<".0\n"; 
  }
  if(type == INT)
  {
    int k = atoi(str.c_str());
    handle_char(k);
    std::cout<<"int : "<<k << "\n";
    std::cout<<"float : "<<k<<".0f\n"; 
    std::cout<<"double : "<<k<<".0\n"; 
  }
  if(type == FLOAT)
  {
    float k = strtof(str.c_str(),NULL);
    handle_char(static_cast<int>(k));
    std::cout<<"int : "<<static_cast<int>(k)<<"\n";
    std::cout<<"float : "<<k<<"f\n";
    std::cout<<"double : "<<k<<"\n";
  }
  if(type == DOUBLE)
  {
    double k = strtod(str.c_str(), NULL);
    handle_char(static_cast<int>(k));
    std::cout<<"int : "<<static_cast<int>(k)<<"\n";
    std::cout<<"float : "<<static_cast<float>(k)<<"f\n";
    std::cout<<"double : "<<k<<"\n";
  }
  if(type == INVALIDE)
  {
    std::cout<<"char : impossible\n";
    std::cout<<"int : impossible\n";
    std::cout<<"float : nanf\n";
    std::cout<<"double : nan\n";
  }
  if(type == INF && (str == "+inf" || str == "+inff"))
  {
    std::cout<<"char : impossible\n";
    std::cout<<"int : impossible\n";
    std::cout<<"float : +inff\n";
    std::cout<<"double : +inf\n";
  }
  if(type == INF && (str == "-inf" || str == "-inff"))
  {
    std::cout<<"char : impossible\n";
    std::cout<<"int : impossible\n";
    std::cout<<"float : -inff\n";
    std::cout<<"double : -inf\n";
  }
}

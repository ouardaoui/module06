#ifndef  SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include<iostream>
#include<string>
#include<stdlib.h>


class ScalarConverter {
  private : 
    char *_str;
    int type;
  public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &cpy);
    ~ScalarConverter(void);
    ScalarConverter &operator=(const ScalarConverter &sc);
    static void convert(std::string str);
      
};

#endif // ! 
  

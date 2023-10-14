#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <exception>

Base * generate(void)
{
    Base *ptr; 
    srand(time(NULL));
    int i = rand() % 3;
    if(i == 0)
      ptr = new A();
    if( i == 1)
      ptr = new B();
    if( i == 2)
      ptr = new C();
    return ptr;
}

void identify(Base* p)
{
  A *a = dynamic_cast<A*>(p);
  if(a)
    std::cout<<"type of class : A"<<std::endl;
  B *b = dynamic_cast<B*>(p);
  if(b)
    std::cout<<"type of class : B"<<std::endl;
  C *c = dynamic_cast<C*>(p);
  if(c)
    std::cout<<"type of class : C"<<std::endl;
}

void identify(Base& p)
{
    try
    {
      (void)dynamic_cast<A&>(p);
      std::cout<<"type of class : A"<<std::endl;
      return ;
    }catch(std::exception &e)
    {
      (void)e;
    }
    try
    {
      (void)dynamic_cast<B&>(p);
      std::cout<<"type of class : B"<<std::endl;
      return ;
    }catch(std::exception &e)
    {
      (void)e;
    }
    try
    {
      (void)dynamic_cast<C&>(p);
      std::cout<<"type of class : C"<<std::endl;
      return ;
    }catch(std::exception &e)
    {
      (void)e;
    }
}

int main()
{
  Base *ptr = generate();
  identify(ptr);
  identify(*ptr);
  delete ptr;
}

#include <iostream>

using namespace std;

class B {
private:
  void privateB() { std::cout << "B::privateB()" << std::endl; }
public:
  void publicB() { std::cout << "B::publicB()" << std::endl; }
protected:
  void protectedB() { std::cout << "B::protectedB()" << std::endl; }
};

class D_priv : private B 
{
public:
  using B::publicB; //now i can use it as public in the exterior of the class

  void doThings() { 
    //B::privateB(); //U can't get here
    B::protectedB();
    B::publicB();
  }
};
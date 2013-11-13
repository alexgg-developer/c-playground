#pragma once
#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

class Singleton
{
public:
  static Singleton & getInstance()
  {
    static Singleton instance;

    return instance;
  }
  int a;
  int b;
private:
  Singleton(){}
  Singleton(Singleton const&);
  void operator=(Singleton const&);
};
#endif

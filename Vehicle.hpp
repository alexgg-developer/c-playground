#pragma once
#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>
#include <iostream>

class Vehicle 
{
public: 
  enum TypeOfTerrain {
    WATER,
    SOIL,
    AIR
  };
  int mNumWheels;
  int mNumDoors;
  TypeOfTerrain mTypeOfTerrain;
  virtual void virtualClassExample() { std::cout << "I'm the base function class" << std::endl; }
  //virtual void pureVirtualClassExample() = 0; //NO SE PUEDE INSTANCIAR ENTONCES, LA CLASE SERIA UNA INTERFAZ ÚNICAMENTE
private:
  std::string mCountry;
protected:
  int mNumSeats;
};

#endif
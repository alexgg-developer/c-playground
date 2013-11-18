#pragma once
#ifndef _CAR_HPP_
#define _CAR_HPP_

#include "Vehicle.hpp"
#include <vector>

class Car : public Vehicle 
{
public: 
  Car() { mTypeOfTerrain = TypeOfTerrain::SOIL;}
  Car(Vehicle* c) { mTypeOfTerrain = c->mTypeOfTerrain; }

  void printCountry();
  void setNumSeats(int numSeats);
  void constPrueba(const std::vector<const int> & v, const int i);
  virtual void virtualClassExample();
};

#endif
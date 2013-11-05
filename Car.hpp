#pragma once
#ifndef _CAR_HPP_
#define _CAR_HPP_

#include "Vehicle.hpp"

class Car : public Vehicle 
{
public: 
  Car() { mTypeOfTerrain = TypeOfTerrain::SOIL;}
  Car(Vehicle* c) { mTypeOfTerrain = c->mTypeOfTerrain; }
};

#endif
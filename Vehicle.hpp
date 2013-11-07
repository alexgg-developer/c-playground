#pragma once
#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>

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
private:
  std::string mCountry;
protected:
  int mNumSeats;
};

#endif
#pragma once
#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

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
};

#endif
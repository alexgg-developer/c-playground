class Vehicle 
{

public: 
  Vehicle();
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
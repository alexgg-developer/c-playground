#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"

int main(int argc, char *argv[]) {
  Vehicle *v = new Vehicle;
  v->mTypeOfTerrain = Vehicle::AIR;
  v->mNumDoors = 4;
  v->mNumWheels = 6;
  Car * car = new Car();
  v = car;
  std:: cout << car->mTypeOfTerrain << std::endl;     
  std:: cout << car->mNumDoors << std::endl;     
  std:: cout << car->mNumWheels << std::endl;   
  v->mTypeOfTerrain = Vehicle::AIR;  
  Car * c = new Car(v);
  std:: cout << c->mTypeOfTerrain << std::endl;     
  std:: cout << c->mNumDoors << std::endl;     
  std:: cout << c->mNumWheels << std::endl;     
  c->setNumSeats(5);
  //Por 19.4
}
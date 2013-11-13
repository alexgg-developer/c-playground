#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Singleton.hpp"

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
  int i = 5;
  std::vector<const int> vec(1, 30); 
  //vec[0] = 30;
  c->constPrueba(vec, i);
  //Por 19.4
  Singleton &S = Singleton::getInstance();
  Singleton &S2 = Singleton::getInstance();
  S.a = 5;
  std::cout << "S.a 1: " << S.a << std::endl;
  std::cout << "S.a 2: " << S2.a << std::endl;
  S2.b = 6;
  std::cout << "S.b 1: " << S.b << std::endl;
  std::cout << "S2.b 2: " << S2.b << std::endl;
}
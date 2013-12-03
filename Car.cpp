#include "Car.hpp"
#include <iostream>

void Car::printCountry()
{
  //std::cout << mCountry << std::endl;    
  //A pesar de q forma parte la clase base al ser private, no puedes acceder.
}

void Car::setNumSeats(int numSeats)
{
  mNumSeats = numSeats;
  std::cout << "Number of seats: " << mNumSeats << std::endl;    
}

void Car::constPrueba(const std::vector<const int> & v, const int i)
{
  std::cout << "v[0] : " << v[0] << " i: " << i << std::endl;
}

void Car::virtualClassExample() { std::cout << "I'm the derived function class" << std::endl; }
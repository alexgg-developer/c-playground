#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Singleton.hpp"
#include <mutex> //THREADS
#include <thread>

void mainInheritance()
{  
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
}
void mainSingleton()
{
  Singleton &S = Singleton::getInstance();
  Singleton &S2 = Singleton::getInstance();
  S.a = 5;
  std::cout << "S.a 1: " << S.a << std::endl;
  std::cout << "S.a 2: " << S2.a << std::endl;
  S2.b = 6;
  std::cout << "S.b 1: " << S.b << std::endl;
  std::cout << "S2.b 2: " << S2.b << std::endl;
}

void threadFunction(std::string textToPrint, unsigned int n)
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << textToPrint << " I'm the thread: " <<  std::this_thread::get_id() << std::endl;
}
void mainMutex()
{
  using namespace std;
  std::thread t1(threadFunction, "Don't walk behind me; I may not lead. Don't walk in front of me; I may not follow. Just walk beside me and be my friend.", 20);
  std::thread t2(threadFunction, "You will never be happy if you continue to search for what happiness consists of. You will never live if you are looking for the meaning of life.", 10);
  std::thread t3(threadFunction, "Integrity has no need of rules.", 15);

  t1.join();
  t2.join();
  t3.join();
}

void mainTypedef()
{
  typedef std::pair<std::string, int> Button;

  Button b("Integrity has no need of rules.", 15);

  std::cout << b.first << " " << b.second << std::endl;
}

void mainVirtual()
{
  Vehicle * v = new Vehicle();
  v->virtualClassExample();
  Car * car = new Car();
  car->virtualClassExample();
  v = car;
  v->virtualClassExample();
  Car * c = new Car(v);
  c->virtualClassExample();
}

int main(int argc, char *argv[]) 
{
  //mainInheritance();
  //mainSingleton();
  //mainMutex();
  //mainTypedef();
  mainVirtual();
}
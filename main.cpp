#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Singleton.hpp"
#include "InheritanceClasses.hpp"
#include "Extern_A.hpp"
#include "Extern_B.hpp"
#include <mutex> //THREADS
#include <thread>
#include <vector>

bool ready = false;
std::mutex mtx;

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
  
  //int i = 5;
  //std::vector<const int> vec(1, 30);  
  // can't be created a vector of const type because in case the vector needs to grow the elements need to be copied
  //vec[0] = 30;
  //c->constPrueba(vec, i);
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
  //FAQ 20
  Vehicle * v = new Vehicle();
  v->virtualClassExample();
  Car * car = new Car();
  car->virtualClassExample();
  v = car;
  v->virtualClassExample();
  Car * c = new Car(v);
  c->virtualClassExample();

  Vehicle* vv = new Vehicle();
  Car* cc = new Car();
  std::vector<Vehicle*> lotsOfV;
  lotsOfV.push_back(vv);
  lotsOfV.push_back(cc);
  lotsOfV[0]->virtualClassExample();
  lotsOfV[1]->virtualClassExample();

  Vehicle vvv;
  Car ccc;
  std::vector<Vehicle> lotsOfVV;
  lotsOfVV.push_back(vvv);
  lotsOfVV.push_back(ccc);
  lotsOfV[0]->virtualClassExample();
  lotsOfV[1]->virtualClassExample();
}

void lock1()
{  
  std::unique_lock<std::mutex> lck(mtx);
  std::cout << "Principio" <<  std::this_thread::get_id() << std::endl;
  while(!ready);
  std::cout << "Final" <<  std::this_thread::get_id() << std::endl;
}

void setReady(unsigned int n)
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  ready = true;
}
void mainLocks()
{
  std::cout << "Main" <<  std::this_thread::get_id() << std::endl;  
  std::thread t1(lock1);
  std::thread t2(lock1);

  std::thread t3(setReady, 15);
  t3.join();
  t1.join();
  t2.join();
}

void mainPrivateInheritance()
{
  D_priv d;
  d.doThings();
  d.publicB();
}

void mainExtern()
{
	//Extern_A::printGA();
	//Extern_B::printGA();
	printGA();
}

int main(int argc, char *argv[]) 
{
  //mainInheritance();
  //mainSingleton();
  //mainMutex();
  //mainTypedef();
  //mainVirtual();
  //mainLocks();
  //mainPrivateInheritance();
  mainExtern();
	getchar();
	return 0;
}
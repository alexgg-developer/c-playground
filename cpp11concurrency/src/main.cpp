#include <iostream>
#include <mutex> //THREADS
#include <thread>
#include <vector>

#include "SimpleThreadsApp.h"
#include "BingoApp.h"
#include "SingletonApp.h"
#include "AsyncThreadApps.h"
#include "ConcurrentQueueApp.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	//return SimpleThreadsMain(argc, argv);
	//return BingoApp::main(argc, argv);
	//return SingletonApp::main(argc, argv);
	//return AsyncThreads::main(argc, argv);
	return ConcurrentQueueApp::main(argc, argv);
}
#pragma once
#include <iostream>
#include <mutex> //THREADS
#include <thread>
#include <vector>
#include <cassert>

using namespace std;

namespace SingletonApp
{	
	std::once_flag winner_flag;

	class Singleton
	{	
	private:
		static Singleton *s_instance;
		Singleton(): value(42) { std::cout << "Singleton ctor" << endl; }
	public:
		int value;

		static Singleton *instance()
		{
			if (s_instance == nullptr) {
				s_instance = new Singleton();
			}
			return s_instance;
		}
	};

	Singleton* Singleton::s_instance = 0;
	int gCtorCalls = 0;
	int gInstanceCalls = 0;

	class SingletonMutex
	{
	private:
		static SingletonMutex *s_instance;
		
		SingletonMutex() { ++gCtorCalls; }
	public:
		static SingletonMutex *instance()
		{			
			static std::mutex m_mutex;
			std::lock_guard<std::mutex> guard(m_mutex);
			++gInstanceCalls;
			if (s_instance == nullptr) {
				s_instance = new SingletonMutex();
			}
			return s_instance;
		}
	};

	SingletonMutex* SingletonMutex::s_instance = 0;

	class SingletonOnce
	{
	private:
		static SingletonOnce *s_instance;
		static once_flag m_flag;
		SingletonOnce() { ++gCtorCalls; }
		static void createInstance() { s_instance = new SingletonOnce(); }
	public:
		static SingletonOnce *instance()
		{
			call_once(m_flag, createInstance);
			return s_instance;
		}
	};

	SingletonOnce* SingletonOnce::s_instance = 0;
	once_flag SingletonOnce::m_flag;

	class MeyerSingleton
	{
	private:		
		MeyerSingleton() { ++gCtorCalls; }
	public:
		static MeyerSingleton& instance()
		{
			static MeyerSingleton s_instance;

			return s_instance;
		}
	};
	
	const int MAX_THREADS = 1000;

	int main(int argc, char *argv[])
	{
		Singleton* s = Singleton::instance();
		s->value += 1;
		s = Singleton::instance();
		assert(s->value == 43 && "the instance has changed");
		std::thread players[MAX_THREADS];
		for (int i = 0; i < MAX_THREADS; ++i) {
			players[i] = std::thread([=] {
				//SingletonMutex *sm = SingletonMutex::instance();
				//SingletonOnce *sm = SingletonOnce::instance();
				MeyerSingleton ms = MeyerSingleton::instance();
			});
		}
		for (int i = 0; i < MAX_THREADS; ++i) {
			players[i].join();
		}
		cout << "gInstanceCalls::" << gInstanceCalls << endl;
		cout << "gCtorCalls::" << gCtorCalls << endl;

		return 0;
	}
}


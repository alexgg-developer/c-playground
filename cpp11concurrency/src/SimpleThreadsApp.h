#pragma once

#include <iostream>
#include <mutex> //THREADS
#include <thread>
#include <vector>

using namespace std;

namespace SimpleThreads
{
	void psin(double angle)
	{
		double sum = 0;
		for (int i = 0; i < 30; ++i) {
			double result = std::sin(angle * 3.14 / 180);
			sum += result;
			std::cout << "partial sin(" << angle << "): " << sum << "\n";
		}
	}

	void pcos(double angle)
	{
		double sum = 0;
		for (int i = 0; i < 30; ++i) {
			double result = std::cos(angle * 3.14 / 180);
			sum += result;
			std::cout << "partial cos(" << angle << "): " << sum << "\n";
		}
	}


	int fib(int n)
	{
		if (n <= 1) return n;
		int fib1, fib2;

		//how we pass fib1 as a reference every thread will access to the same memory address, giving possible problems of concurrency
		//for example a thread modifies fib1 and then other also modifies it, so fib1 has the value of the last thread it has modified the
		//variable.
		std::thread t([=, &fib1] { fib1 = fib(n - 1); });
		std::thread::id threadID = t.get_id();
		fib2 = fib(n - 2);
		if (fib2 < 0) throw std::runtime_error("Negative value");
		t.join();
		/*cout << "---thread " << threadID << "----" << endl;
		cout << "n:" << n << endl;
		cout << "fib1:" << fib1 << endl;
		cout << "fib2:" << fib2 << endl;*/

		return fib1 + fib2;
	}

	int SimpleThreadsMain(int argc, char *argv[])
	{
		//std::thread hello([] { std::cout << "Hello world" << std::endl; });
		//std::cout << std::thread::hardware_concurrency() << std::endl; //cores
		//hello.join();
		//cout << fib(12) << endl;
		std::thread thread_one(psin, 30);
		std::thread thread_two;
		cout << "thread_one id::" << thread_one.get_id() << endl;
		cout << "thread_two id::" << thread_two.get_id() << endl;
		cout << "--- swap ---" << endl;
		thread_two.swap(thread_one);
		cout << "--- pcos assign ---" << endl;
		thread_one = std::thread(pcos, 30.0);
		cout << "thread_one id::" << thread_one.get_id() << endl;
		cout << "thread_two id::" << thread_two.get_id() << endl;

		thread_one.join(); //if you don't use join an exception is thrown
		thread_two.join();

		return 0;
	}
}

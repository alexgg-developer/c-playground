#pragma once

#include <iostream>
#include <future>
#include <vector>
#include <random>
#include <queue>

using namespace std;

namespace ConcurrentQueueApp
{
	const int NUMBERS_TO_GENERATE = 10;
	template <class T>
	class ConcurrentQueue
	{
	public:
		void send(T item) 
		{
			lock_guard<mutex> guard(m_mutex);
			m_queue.push(item);
		}

		T receive() 
		{
			lock_guard<mutex> guard(m_mutex);
			T item = m_queue.front();
			m_queue.pop();
			return item;
		}

		bool empty()
		{
			lock_guard<mutex> guard(m_mutex);
			return m_queue.empty();
		}
	private:
		queue<T> m_queue;
		mutex m_mutex;
	};

	void producer(ConcurrentQueue<int>& q)
	{
		std::default_random_engine dre(0x111);
		std::uniform_int_distribution<int> id(10, 1000);
		for (int i = 0; i < NUMBERS_TO_GENERATE; ++i) {
			int n = id(dre);
			cout << "Generated number " << n << "." << endl;
			q.send(n);
		}
	}

	void consumer(ConcurrentQueue<int>& q)
	{
		for (int i = 0; i < NUMBERS_TO_GENERATE; ++i) {
			if (!q.empty()) {
				int n = q.receive();
				cout << "Received number " << n << endl;
			}
		}
	}

	int main(int argc, char *argv[])
	{
		ConcurrentQueue<int> cQueue;
		
		try {
			//producer(cQueue);
			auto prod1 = std::async(std::launch::async, producer, std::ref(cQueue));			
			auto prod2 = std::async(std::launch::async, producer, std::ref(cQueue));
			auto consum = std::async(std::launch::async, consumer, std::ref(cQueue));
			prod1.wait();
			prod2.wait();
			consum.wait();
		}
		catch (std::exception& e) {
			cout << e.what() << endl;
		}
		//semaphore? https://stackoverflow.com/questions/27652939/best-way-for-waiting-for-callback-to-finish
		//https://stackoverflow.com/questions/4792449/c0x-has-no-semaphores-how-to-synchronize-threads
		return 0;
	}
}

#pragma once

#pragma once

#include <iostream>
#include <future>
#include <vector>

using namespace std;

namespace AsyncThreads
{
	double psin(double angle)
	{
		double sum = 0;
		for (int i = 0; i < 30; ++i) {
			double result = std::sin(angle * 3.14 / 180);
			sum += result;
			std::cout << "partial sin(" << angle << "): " << sum << "\n";
		}
		return sum;
	}

	double pcos(double angle)
	{
		double sum = 0;
		for (int i = 0; i < 30; ++i) {
			double result = std::cos(angle * 3.14 / 180);
			sum += result;
			std::cout << "partial cos(" << angle << "): " << sum << "\n";
		}

		return sum;
	}


	int main(int argc, char *argv[])
	{

		auto handleSin = std::async(std::launch::async, psin, 30);
		auto handleCos = std::async(std::launch::async, pcos, 30);
		std::future<double> fd;
		//std::future<double> fd = std::move(handleSin);
		//cout << "handleSin psin::" << handleSin.get() << endl; //invalid
		fd = std::move(handleSin);		
		//cout << "handleSin psin::" << handleSin.get() << endl; //invalid
		cout << "fd psin::" << fd.get() << endl;
		cout << "handleCos psin::" << handleCos.get() << endl;

		return 0;
	}
}
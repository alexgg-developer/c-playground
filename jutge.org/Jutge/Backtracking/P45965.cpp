#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void backtrackZerosAndOnes(size_t iterations, vector<size_t>& numbers, size_t totalZeros, size_t currentNumberOfZeros)
{
	if (iterations > 0) {
		size_t i = numbers.size() - iterations;
		if (currentNumberOfZeros < totalZeros) {
			numbers[i] = 0;
			backtrackZerosAndOnes(iterations - 1, numbers, totalZeros, currentNumberOfZeros + 1);
		}
		if (i - currentNumberOfZeros < numbers.size() - totalZeros) {
			numbers[i] = 1;
			backtrackZerosAndOnes(iterations - 1, numbers, totalZeros, currentNumberOfZeros);
		}
	}
	else {
		for (size_t i = 0; i < std::max(numbers.size() - 1, static_cast<size_t>(0)); ++i) {
			cout << numbers[i] << " ";
		}
		if (numbers.size() > 0) {
			cout << numbers[numbers.size() - 1] << endl; 
		}
	}
}


int main()
{
	size_t totalNumbers, ones;
	totalNumbers = 1;
	ones = 1;
	cin >> totalNumbers >> ones;
	vector<size_t> numbers;
	for (size_t i = 0; i < totalNumbers; ++i) {
		numbers.push_back(3);
	}
	size_t totalZeros = totalNumbers - ones;
	size_t currentNumberOfZeros = 0;
	backtrackZerosAndOnes(totalNumbers, numbers, totalZeros, currentNumberOfZeros);
}



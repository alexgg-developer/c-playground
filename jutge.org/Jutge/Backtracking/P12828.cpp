#include <vector>
#include <iostream>

using namespace std;

void backtrackZerosAndOnes(size_t iterations, vector<size_t> numbers)
{
	if (iterations > 0) {	
		numbers[numbers.size() - iterations] = 0;
		backtrackZerosAndOnes(iterations - 1, numbers);
		numbers[numbers.size() - iterations] = 1;
		backtrackZerosAndOnes(iterations - 1, numbers);
	}
	else {
		for (size_t i = 0; i < numbers.size() - 1; ++i) {
			cout << numbers[i] << " ";
		}
		cout << numbers[numbers.size() - 1] << endl;
	}
}


int main()
{
	size_t iterations = 0;
	cin >> iterations;
	vector<size_t> numbers(iterations);

	backtrackZerosAndOnes(iterations, numbers);
}



#include <iostream>
#include <vector>

using namespace std;

/*
Implement a void function F that takes pointers to two arrays of integers (A and B) 
and a size N as parameters. It then populates B where B[i] is the product of all A[j] 
where j != i.

For example: If A = {2, 1, 5, 9}, then B would be {45, 90, 18, 10}.
*/

/*void F(const vector<int>&A, vector<int>& B)
{
	int totalMultiplication = A[0];
	for (size_t i = 1; i < A.size(); ++i) {
		totalMultiplication *= A[i];
	}

	for (size_t i = 0; i < A.size(); ++i) {
		//totalMultiplication *= A[i];
		if (A[i] != 0) {
			B[i] = totalMultiplication / A[i];
		}
	}
}*/

//Alternative without if and divisions:
void F(const vector<int>&A, vector<int>& B) {
	// Set prod to the neutral multiplication element
	int prod = 1;

	for (int i = 0; i < A.size(); ++i) {
		// For element "i" set B[i] to A[0] * ... * A[i - 1]
		B[i] = prod;
		// Multiply with A[i] to set prod to A[0] * ... * A[i]
		prod *= A[i];
	}

	// Reset prod and use it for the right elements
	prod = 1;

	for (int i = A.size() - 1; i >= 0; --i) {
		// For element "i" multiply B[i] with A[i + 1] * ... * A[N - 1]
		B[i] *= prod;
		// Multiply with A[i] to set prod to A[i] * ... * A[N - 1]
		prod *= A[i];
	}
}

/*int main()
{
	vector<int> A  { 2, 1, 5, 9 };
	vector<int> B (4, 0);

	F(A, B);

	for (size_t i = 0; i < B.size(); ++i) {
		cout << B[i] << endl;
	}
}*/
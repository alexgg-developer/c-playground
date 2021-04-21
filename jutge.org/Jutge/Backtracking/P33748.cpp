#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;

void backtrackSubset(size_t index, const vector<string>& words, vector< vector<string> >& res,
	vector<string>& subset, const int subsetSize)
{
	for (size_t i = index; i < words.size(); ++i) {
		subset.push_back(words[i]);
		if (subset.size() == subsetSize) {
			res.push_back(subset);
		}
		else if (subset.size() < subsetSize) {
			backtrackSubset(i + 1, words, res, subset, subsetSize);
		}
		subset.pop_back();
	}
}

//test to calculate the number of entries in vector C(2,5)
//test to calculate with subsetsize calculated.
//test with global variables.
//measure time with chrono

void backtrackSubset(size_t index, const vector<string>& words, vector< vector<string> >& res,
	vector<string>& subset, int currentSubsetSize, const int subsetSize)
{
	for (size_t i = index; i < words.size(); ++i) {
		//subset.push_back(words[i]);
		subset[currentSubsetSize++] = words[i];
		if (currentSubsetSize == subsetSize) {
			res.push_back(subset);
		}
		else if (currentSubsetSize < subsetSize) {
			backtrackSubset(i + 1, words, res, subset, currentSubsetSize, subsetSize);
		}
		//subset.pop_back();
		--currentSubsetSize;
	}
}

void backtrackSubset(size_t index, const vector<string>& words, vector< vector<string> >& res,
	vector<string>& subset, int currentSubsetSize, size_t& currentResSize, const size_t subsetSize)
{
	for (size_t i = index; i < words.size(); ++i) {
		subset[currentSubsetSize++] = words[i];
		if (currentSubsetSize == subsetSize) {
			//res.push_back(subset);
			res[currentResSize++] = subset;
		}
		else if (currentSubsetSize < subsetSize) {
			backtrackSubset(i + 1, words, res, subset, currentSubsetSize, currentResSize, subsetSize);
		}
		--currentSubsetSize;
	}
}

size_t nChoosek(size_t n, size_t k)
{
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	size_t result = n;
	for (size_t i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

int main()
{
	size_t subsetSize;
	cin >> subsetSize;
	//subsetSize = 2;
	size_t totalWords;
	cin >> totalWords;
	//vector<string> words = { "hola", "adeu", "hi" };
	//vector<string> words = { "hola", "adeu", "hi", "hello", "bye" };
	//totalWords = words.size();
	vector<string> words(totalWords);
	vector<string> subset(subsetSize);
	size_t subsets = nChoosek(totalWords, subsetSize);
	vector< vector<string> > res(subsets);
	if (subsetSize == 0) {
		res.push_back(subset);
	}
	else if (subsetSize > totalWords) {

	}
	else {
		string word;
		//words.reserve(totalWords);
		for (size_t i = 0; i < totalWords; ++i) {
			cin >> word;
			//words.push_back(word);
			words[i] = word;
		}
		//subset.reserve(subsetSize);

		auto start = std::chrono::system_clock::now();
		//time base: 238 244 243 242 245
		//backtrackSubset(0, words, res, subset, subsetSize);
		//subset reserved time: 196 191 193 191 191 
		//backtrackSubset(0, words, res, subset, 0, subsetSize);
		//res reserved time: 94 94 94 85 86 92
		size_t currentResSize = 0;
		backtrackSubset(0, words, res, subset, 0, currentResSize, subsetSize);
		auto end = std::chrono::system_clock::now();
		auto elapsed =
			std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		//std::cout << elapsed.count() << '\n';

		for (size_t i = 0; i < res.size(); ++i) {
			cout << "{";
			for (size_t j = 0; j < res[i].size(); ++j) {
				if (j > 0 && res[i].size() > 1) {
					cout << ",";
				}
				cout << res[i][j];
			}
			cout << "}" << endl;
		}
	}

}



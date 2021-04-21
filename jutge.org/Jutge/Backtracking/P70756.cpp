#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*void partitions(size_t index, size_t resIndex, const vector<string>& words, vector<vector<vector<string>>>& res)
{
	//for (size_t j = resIndex; j < res.size(); ++j) {
	for (size_t i = 0; i < words.size(); ++i) {
		vector<vector<string>> currentSubsets = res[0];
		currentSubsets
		//partitions[index % words.size()].push_back(words[i]);		
		/*if (index < words.size()) {
			partitions(index + 1, words, res);
		}
		res[index].push_back(words[i]);*/
		//subset.back();
		//subset.pop_back();
	/*}
	//}
	//partitions(index + 1, words, res, subset);
}*/


void partitions(size_t indexWord, size_t resIndex, size_t resSubset, const vector<string>& words, vector<vector<vector<string>>>& res)
{	
	auto& currentResult = res[resIndex];
	for (size_t i = indexWord; i < words.size(); ++i) {
		currentResult[resSubset].push_back(words[indexWord]);
		if (resSubset < currentResult.size() - 1) {
			//careful resIndex should be the subsetIndex an then add next dimension (resSubset+1, resIndex+1)
			partitions(i, resIndex+1, resSubset+1, words, res);
		}
	}
}


void backtrackSubset(size_t index, const vector<string>& words, vector< vector<string> >& res,
	vector<string>& subset)
{
	for (size_t i = index; i < words.size(); ++i) {
		subset.push_back(words[i]);
		
		res.push_back(subset);
		backtrackSubset(i + 1, words, res, subset);
		subset.pop_back();
	}
}

bool acceptableSubsets(vector< vector<string>> subsets, size_t wordSize)
{
	size_t totalWords = 0;

	for (size_t i = 0; i < subsets.size(); ++i) {
		totalWords += subsets[i].size();
	}

	return totalWords == wordSize;
}

void backtrackSubsets(size_t index, size_t currentSubset, const vector<string>& words, vector<vector< vector<string>>>& res,
	vector< vector<string>>& subsets)
{
	for (size_t i = index; i < words.size(); ++i) {
		//vector< vector<string>>& subsets = res[currentRes];;
		subsets[currentSubset].push_back(words[i]);
		if (acceptableSubsets(subsets, words.size())) {
			res.push_back(subsets);
		}
		else {
			backtrackSubsets(i + 1, currentSubset, words, res, subsets);
		}
		subsets[currentSubset].pop_back();
		if (currentSubset < subsets.size() - 1) {
			backtrackSubsets(i, currentSubset+1, words, res, subsets);
		}
		//subsets.pop_back();
	}
}

int main()
{
	size_t numberSubsets;
	//cin >> numberSubsets;
	numberSubsets = 2;
	size_t totalWords;
	//cin >> totalWords;
	vector<string> words = { "hello", "bye" };
	//totalWords = words.size();
	//vector<string> words;
	vector<string> subset;
	vector<vector< vector<string> >> res(numberSubsets * numberSubsets);
	for (size_t i = 0; i < res.size(); ++i) {
		res[i].resize(numberSubsets);
	}
	string word;
	/*words.reserve(totalWords);
	for (size_t i = 0; i < totalWords; ++i) {
		cin >> word;
		words.push_back(word);
	}*/


	partitions(0, 0, 0, words, res);

	std::cout << "end" << std::endl;
	/*for (size_t i = 0; i < res.size(); ++i) {
		cout << "subset " << i + 1 << ": {";
		for (size_t j = 0; j < res[i].size(); ++j) {
			if (j > 0) {
				cout << ",";
			}
			cout << res[i][j];
		}
		cout << "}" << endl;
	}*/

}



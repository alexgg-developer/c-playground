#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

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
	vector<string> words;
	vector<string> subset;
	vector< vector<string> > res;
	if (subsetSize == 0) {
		res.push_back(subset);
	}
	else {
		string word;
		words.reserve(totalWords);
		for (size_t i = 0; i < totalWords; ++i) {
			cin >> word;
			words.push_back(word);
		}

		backtrackSubset(0, words, res, subset, subsetSize);

		for (size_t i = 0; i < res.size(); ++i) {
			cout << "{";
			for (size_t j = 0; j < res[i].size(); ++j) {
				if (j > 0) {
					cout << ",";
				}
				cout << res[i][j];
			}
			cout << "}" << endl;
		}
	}

}



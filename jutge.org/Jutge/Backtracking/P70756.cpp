#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void partitions(size_t index, const vector<string>& words, vector< vector<string> >& res,
	vector<string>& subset)
{
	for (size_t i = index; i < words.size(); ++i) {
		subset.push_back(words[i]);
		res.push_back(subset);
		partitions(i + 1, words, res, subset);
		subset.back();
		subset.pop_back();
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
	vector< vector<string> > res(numberSubsets);
	string word;
	/*words.reserve(totalWords);
	for (size_t i = 0; i < totalWords; ++i) {
		cin >> word;
		words.push_back(word);
	}*/


	partitions(0, words, res, subset);

	for (size_t i = 0; i < res.size(); ++i) {
		cout << "subset " << i + 1 << ": {";
		for (size_t j = 0; j < res[i].size(); ++j) {
			if (j > 0) {
				cout << ",";
			}
			cout << res[i][j];
		}
		cout << "}" << endl;
	}

}



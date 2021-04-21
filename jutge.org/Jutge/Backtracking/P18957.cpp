#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*void backtrackZerosAndOnes(size_t numberOfWords, size_t addedWords, const vector<string>& words, vector<string>& output,
	vector<bool>& added)
{
	if (addedWords < numberOfWords) {
		for (size_t i = 0; i < words.size(); ++i) {
			if (!added[i]) {
				output[addedWords] = words[i];
				added[i] = true;
				backtrackZerosAndOnes(numberOfWords, addedWords + 1, words, output, added);
				//added[i] = false;
			}
		}
	}
	else {
		cout << "{";
		for (size_t i = 0; i < addedWords; ++i) {
			if (i > 0) cout << ",";
			cout << output[i];
		}
		cout << "}" << endl;
	}
}*/

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

int main()
{
	size_t totalWords;
	totalWords = 3;
	//cin >> totalWords;
	vector<string> words = { "hola", "adeu", "hi" };
	//vector<string> words = { "h", "x", "y" };
	vector<string> subset;
	vector< vector<string> > res;
	res.push_back(subset);
	/*vector<string> words;
	string word;
	words.reserve(totalWords);
	for (size_t i = 0; i < totalWords; ++i) {
		cin >> word;
		words.push_back(word);
	}*/

	backtrackSubset(0, words, res, subset);

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



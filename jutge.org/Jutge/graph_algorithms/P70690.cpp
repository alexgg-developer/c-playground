#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char EMPTY = '.';
char OBSTACLE = 'x';
char TREASURE = 't';

bool findTreasure(size_t rows, size_t columns, const std::vector<char>& map, size_t startRow, size_t startColumn)
{
	
}

int main()
{
	std::vector<char> map;	
	size_t rows, columns;
	cin >> rows >> columns;
	rows = 7;
	columns = 6;
	map.resize(rows * columns);
	
	char scribble;
	for (size_t i = 0; i < map.size(); ++i) {
		cin >> scribble;
		map[i] = scribble;
	}

	size_t startRow, startColumn;
	cin >> startRow >> startColumn;

	cout << rows << std::endl;
	cout << columns << std::endl;

	if (findTreasure(rows, columns, map, startRow, startColumn)) {
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
}



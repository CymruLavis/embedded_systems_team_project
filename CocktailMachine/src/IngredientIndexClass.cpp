
#include "../Include/Indexes.h"

#include <iostream>
#include <vector>
#include <string>

vector<string> IngredientIndexes::getCol(vector<vector<string>> data, int colIndex) {
	vector<string> thisList;
	for (const auto& row : data) {
		thisList.push_back(row[colIndex]);
	}
	return thisList;
}

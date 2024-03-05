
#include "../Include/Indexes.h"

#include <iostream>
#include <vector>
#include <string>

vector<string> IngredientIndexes::getIngredients(vector<vector<string>> data) {
	vector<string> thisList;
	for (const auto& row : data) {
		thisList.push_back(row[0]);
	}
	return thisList;
}
vector<string> IngredientIndexes::getIndexes(vector<vector<string>> data) {
	vector<string> thisList;
	for (const auto& row : data) {
		thisList.push_back(row[1]);
	}
	return thisList;
}

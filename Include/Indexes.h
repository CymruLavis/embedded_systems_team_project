#ifndef INGREDIENT_INDEXES_H
#define INGREDIENT_INDEXES_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IngredientIndexes {
public:
	vector<string> ingredients;
	vector<string> indexes;
	vector<vector<string>> df;
	
	vector<string>  getIngredients(vector<vector<string>> data);
	vector<string>  getIndexes(vector<vector<string>> data);
	
};


#endif

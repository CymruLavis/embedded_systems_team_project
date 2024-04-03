#ifndef DATA_H
#define DATA_H

#include "Indexes.h"
#include "SystemConfig.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Data {
public:
	vector<vector<string>> df_menu;
	string data_file_path;
	string indexes_file_path;
	IngredientIndexes ingredient_indexes;
	// SystemConfig sys;
	
	Data();
	
	string getFilePath();
	string getIndexFilePath();
	
	vector<vector<string>> getData(string filePath);
	
	vector<string> getIngredients();
	
	string getDrinkDescription(string drink);
	
	vector<int> getRecipe(string drink, SystemConfig sys);
	
	vector<string> getActiveDrinkList(vector<string> ingredients);
	bool isDrinkMakable(vector<string> recipie, vector<string> ingredients);
	
	vector<string> getWholeDrinkList();
	string indexToIngredient(int ingredient_idx);
	int ingredientToIndex(string ingredient);

	vector<string> split_line(string line, char delimiter);
	int append_CSV(string pose_value, string ingredient_value);

};

#endif

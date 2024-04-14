#ifndef DATA_H
#define DATA_H

#include "Indexes.h"

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
	vector<vector<string>> fill_data;
	// SystemConfig sys;
	
	Data();
	
	string getFilePath();
	string getIndexFilePath();
	string getPoseFilePath();
	
	vector<vector<string>> getData(string filePath);
	
	vector<string> getIngredients();
	
	string getDrinkDescription(string drink);
	
	vector<int> getRecipe(string drink);
	int getPosition(int ing_idx);
	vector<string> getActiveDrinkList();
	bool isDrinkMakable(vector<string> recipie);
	vector<string> getColumn(vector<vector<string>> data, int colIdx);
	vector<string> getWholeDrinkList();
	string indexToIngredient(int ingredient_idx);
	int ingredientToIndex(string ingredient);

	vector<string> split_line(const string& line, char delimiter);
	int append_CSV(string pose_value, string ingredient_value);
	int updateVolume(string bottle_position );


};

#endif

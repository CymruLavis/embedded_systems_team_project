#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
//#include <filesystem>
#include <Windows.h>
#include <unordered_set>

using namespace std;
class IngredientIndexes {
public:
	vector<string> ingredients;
	vector<string> indexes;
	vector<vector<string>> df;

	void setIngredients(vector<vector<string>> data) {
		for (const auto& row : data) {
			this->ingredients.push_back(row[0]);
		}
	}
	void setIndexes(vector<vector<string>> data) {
		for (const auto& row : data) {
			this->indexes.push_back(row[1]);
		}
	}
};

class Data {
public:
	vector<vector<string>> df_menu;
	IngredientIndexes ingredient_indexes;
	
	Data() {
		this->df_menu = getData(getFilePath());
		this->ingredient_indexes.df = getData(getIndexFilePath());
		this->ingredient_indexes.setIngredients(this->ingredient_indexes.df);
		this->ingredient_indexes.setIndexes(this->ingredient_indexes.df);

	}
	
	// returns the location of the menu csv
	string getFilePath() {return R"(C:\Users\Ethan Lavis\Desktop\School\Embedded Systems\team project\cocktail_table.csv)";}
	string getIndexFilePath() { return R"(C:\Users\Ethan Lavis\Desktop\School\Embedded Systems\team project\index_table.csv)";}
	// returns a 2D matix of all data from the given csv
	vector<vector<string>> getData(string filePath) {
		ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Failed to open the file" << endl;
			return {};
		}
		vector<vector<string>> data;

		//remove the encoding symbol and gets the first row of data
		string line;
		if (getline(file, line)) {
			if (line.size() >= 3 && line[0] == '\xEF' && line[1] == '\xBB' && line[2] == '\xBF') {
				// UTF-8 BOM detected, discard it
				line.erase(0, 3);
			}
			// Process the rest of the line
			vector<string> row;
			stringstream ss(line);
			string token;
			while (getline(ss, token, ',')) {
				row.push_back(token);
			}
			data.push_back(row);
		}

		// gets the rest of the data out of the csv
		while (getline(file, line)) {
			vector<string> row;
			stringstream ss(line);
			string token;

			while (getline(ss, token, ',')) {
				row.push_back(token);
			}
			data.push_back(row);
		}
		file.close();
		return data;
	}
	
	// Gets all unique ingredients in the menu --> to be used when configuring the carousel
	vector<string> getIngredients() { 
		return this->ingredient_indexes.ingredients;
		//unordered_set<string> ingredients;
		//vector<string> results;
		//for (const auto& row : this->df_menu) {
		//	for (size_t i = 1; i < row.size()-2; i += 2) {
		//		// Check if the item is already in the set			
		//		if (ingredients.find(row[i]) == ingredients.end() && row[i] != "N/A") {
		//			// If not found, add it to the set and result vector
		//			ingredients.insert(row[i]);
		//			results.push_back(row[i]);
		//		}
		//		
		//	}
		//}
		//return results;

	}
	
	// returns the string for a selected drink --> to be inputed into the UI textbox when a drink is selected
	string getDrinkDescription(string drink) {
		vector<string> drink_list = this->getWholeDrinkList();
		int row_index = 0;
		for (int i = 0; i < drink_list.size(); i++) {
			if (drink_list[i] == drink) {
				row_index = i;
			}
		}
		return this->df_menu[row_index][13];

	}
	
	vector<vector<string>> getRecipe(string drink) {
		// Need position of ingredients
		// make queue of positions to visit
		// make quantities of how many times the drink needs to dispense
		// update 
	}

	// returns of list of the drinks that can be made with the loaded ingredients
	vector<string> getActiveDrinkList(vector<string> ingredients) {
		vector<string> drinkList;
		for (const auto& row : this->df_menu) {
			string drink =row[0];
			bool flag = isDrinkMakable(row, ingredients);
			if (flag) {
				drinkList.push_back(row[0]);
			}
			else {
			}
		}
		return drinkList;
	}
	// used by getActiveDrinkList to check if a drink from our menu is able to be made from the loaded ingredients
	bool isDrinkMakable(vector<string> recipie, vector<string> ingredients) {
		bool flag = false;
		for (int i = 1; i < recipie.size() - 2; i += 2) {
			if (recipie[i] == "4") {
				break;
			}
			else {
				
				auto ing = find(ingredients.begin(), ingredients.end(), recipie[i]);
				if (ing == ingredients.end()) {
					return false;
				}
			}
		}

		return true;
	}
	
	//returns a list of all drinks in the menu --> used by getDrinkDescription
	vector<string> getWholeDrinkList() {
		vector<string> drinkList;
		// strange character ??? to fix 
		for (const auto& row : this->df_menu) {
			drinkList.push_back(row[0]);
		}
		return drinkList;
	}

	string indexToDrink(int drinkIndex) {
		return this->ingredient_indexes.ingredients[drinkIndex];
	}
};

class Ingredient {
public:
	string ingredient;
	int fillLevel;
	int position;
	
	Ingredient(string ing, int pos) {
		this->setFillLevel(100);
		this->setIngredient(ing);
		this->setPosition(pos);
	}

	string getIngredient() {return this->ingredient;}
	void setIngredient(string ingred) {this->ingredient = ingred;}

	int getFillLevel() {return this->fillLevel;}
	void setFillLevel(int level) {this->fillLevel = level;}
	
	int getPosition() {return this->position;}
	void setPosition(int pos) {this->position = pos;}
};


void printData(vector<string> data);

int main() {
	Data* conn = new Data();
	vector<string> ingredients = { "Gin", "Cointreau", "Vodka", "Lime Juice", "simple syrup", "Cranberry Juice"};
	vector<string> drinkList = conn->getActiveDrinkList(ingredients);
	printData(drinkList);
}

void printData(const vector<string> data) {
	for (const string& str : data) {
		cout << str << endl;
	}
}

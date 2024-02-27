#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_set>

using namespace std;

class data {
public:
	vector<vector<string>> df_menu;
	
	data() {
		df_menu = getData(getFilePath());
	}
	string getFilePath() {
		return R"(C:\Users\Ethan Lavis\Desktop\School\Embedded Systems\team project\cocktail_table.csv)";
	}
	vector<vector<string>> getData(string filePath) {
		ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Failed to open the file" << endl;
			return {};
		}
		vector<vector<string>> data;

		string line;
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
	vector<string> getIngredients() {
		unordered_set<string> ingredients;
		vector<string> results;

		for (const auto& row : this->df_menu) {
			for (size_t i = 1; i < row.size()-2; i += 2) {
				// Check if the item is already in the set
				if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12) {
					if (ingredients.find(row[i]) == ingredients.end()) {
						// If not found, add it to the set and result vector
						ingredients.insert(row[i]);
						results.push_back(row[i]);
					}
				}
				
			}
		}

		return results;

	}
	vector<vector<string>> getDrinkDescription(string drink) {
	}
	vector<vector<string>> getRecipe(string drink) {

	}
	vector<vector<string>> getDrinkList(vector<string> ingredients) {
	}
};
class Ingredient {
public:
	string ingredient;
	int fillLevel;
	
	string getIngredient() {

	}
	int getFillLevel() {

	}
	void setIngredient(string ingred) {

	}
	void setFillLevel(int level) {


	}
};

int main() {

	return 0;
}
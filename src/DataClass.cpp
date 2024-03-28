#include "../Include/Data.h"
#include "../Include/Indexes.h"
#include "../Include/Ingredient.h"
#include "../Include/SystemConfig.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <filesystem>


namespace fs = std::filesystem;
using namespace std;

	
Data::Data(){
	this->df_menu = getData(getFilePath());
	this->ingredient_indexes.df = getData(getIndexFilePath());
	this->ingredient_indexes.ingredients = this->ingredient_indexes.getCol(this->ingredient_indexes.df,0);
	this->ingredient_indexes.indexes = this->ingredient_indexes.getCol(this->ingredient_indexes.df,1);
}

// returns the location of the menu csv
string Data::getFilePath() {return R"(/home/admin/Desktop/cocktail_machine/Data/cocktail_table.csv)";}
string Data::getIndexFilePath() { return R"(/home/admin/Desktop/cocktail_machine/Data/index_table.csv)";}

// returns a 2D matix of all data from the given csv
vector<vector<string>> Data::getData(string filePath) {
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
vector<string> Data::getIngredients() { 
	return this->ingredient_indexes.ingredients;
}

// returns the string for a selected drink --> to be inputed into the UI textbox when a drink is selected
string Data::getDrinkDescription(string drink) {
	vector<string> drink_list = this->getWholeDrinkList();
	int row_index = 0;
	for (size_t i = 0; i < drink_list.size(); i++) {
		if (drink_list[i] == drink) {
			row_index = i;
		}
	}
	return this->df_menu[row_index][13];

}

vector<int> Data::getRecipe(string drink, SystemConfig sys) {
	vector<string> drink_row;
	vector<int> ings;
	vector<int> quantity;
	// vector<int> pos;
	//"N/A" = 4
	for(const auto& row: this->df_menu){
		if(row[0] == drink){
			drink_row = row;
			break;
		}
	}
	for(int i = 1; i < drink_row.size()-1; i++){
		if (i % 2 == 0) {
			quantity.push_back(stoi(drink_row[i]));
		}
		else{
			ings.push_back(stoi(drink_row[i]));
		}		
	}

	// vector<vector<int>> allData;
	// allData.push_back(ings);
	// allData.push_back(quantity);
	vector<int> positionQueue;
	for(int i = 0; i < ings.size(); i++){
		int pos = sys.getPosition(ings[i]);
		for(int j = 0; j < quantity[i]; j++){
			positionQueue.push_back(pos);
		}
	}
	// Need position of ingredients
	// make queue of positions to visit
	// make quantities of how many times the drink needs to dispense 

	return positionQueue;
}

// returns of list of the drinks that can be made with the loaded ingredients
vector<string> Data::getActiveDrinkList(vector<string> ingredients) {
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
bool Data::isDrinkMakable(vector<string> recipie, vector<string> ingredients) {
	for (size_t i = 1; i < recipie.size() - 2; i += 2) {
		if (recipie[i] == "4") {
			break;
		}
		else {
			
			auto ing = std::find(ingredients.begin(), ingredients.end(), recipie[i]);
			if (ing == ingredients.end()) {
				return false;
			}
		}
	}

	return true;
}

//returns a list of all drinks in the menu --> used by getDrinkDescription
vector<string> Data::getWholeDrinkList() {
	vector<string> drinkList;
	// strange character ??? to fix 
	for (const auto& row : this->df_menu) {
		drinkList.push_back(row[0]);
	}
	return drinkList;
}

string Data::indexToIngredient(int ingredient_idx) {
	return this->ingredient_indexes.ingredients[ingredient_idx-1];
}
int Data::ingredientToIndex(string drink) {
	vector<string> vec = Data::ingredient_indexes.ingredients;

	for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == drink) {
            return i+1; // Found the target string, return its index
        }
    }
    return -1;
}

//Function to save a 6 by 3 matrix represented as vector of strings to a CSV file
void Data::convertToCsvFile(vector<vector<string>>matrix, string filenamePath){
	// Constructing the relative path to the file
    fs::path filepath = fs::current_path() / filenamePath;
	
    ofstream file(filepath);
    if (file.is_open()) {
        // Writing matrix data to the file, loop through each row in  the matrix
        for (const auto& row : matrix) {
			// Loop over each element in the current row
            for (size_t i = 0; i < row.size(); ++i) {
				// Write the current element to the file
                file << row[i];
				// If it's not the last element in the row, add a comma
                if (i != row.size() - 1) {
                    file << ",";
                }
            }
            file << endl;
        }
        file.close();
        //cout << "Matrix saved to " << filepath << " successfully." << endl;
    } else {
        // Print error message if file cannot be opened
        cerr << "Unable to open file: " << filepath << endl;
    }

}

// Function to read a 6 by 3 matrix from a CSV file
vector<vector<string>> Data::readCsvFile(string matrixFilepath){
	vector<vector<string>> matrix;
	// Constructing the relative path to the file
    fs::path filepath = fs::current_path() / matrixFilepath;
	ifstream file(filepath);
    if (file.is_open()) {
        string line;
        // Read each line of the file
        while (getline(file, line)) {
			//vector to store the elements of the current row
            vector<string> row;
			//Create a stringstream to split the line into individual elements
            stringstream ss(line);
            string cell;
            // Loop to extract each element from the stringstream
        // and add it to the current row
            while (getline(ss, cell, ',')) {
                row.push_back(cell);
            }
            // Add the current row to the matrix
            matrix.push_back(row);
        }
        file.close();
        //cout << "Matrix read from " << filepath << " successfully." << endl;
    } else {
        // Print error message if file cannot be opened
        cerr << "Unable to open file: " << filepath << endl;
    }
    return matrix;
}



    


    //string filenamePath = "matrix_data.csv";

    //saveMatrixToCSV(matrix, filenamePath);

    //vector<vector<string>> readMatrix = readMatrixFromCSV(filenamePath);


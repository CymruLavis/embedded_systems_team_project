#include "../Include/Data.h"
#include "../Include/Indexes.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>



using namespace std;

	
Data::Data(){
	this->df_menu = getData(getFilePath());
	this->ingredient_indexes.df = getData(getIndexFilePath());
	this->ingredient_indexes.ingredients = this->ingredient_indexes.getCol(this->ingredient_indexes.df,0);
	this->ingredient_indexes.indexes = this->ingredient_indexes.getCol(this->ingredient_indexes.df,1);
	this->fill_data = getData(getPoseFilePath());
}

// returns the location of the menu csv
string Data::getFilePath() {return R"(../Data/cocktail_table.csv)";}
string Data::getIndexFilePath() { return R"(../Data/index_table.csv)";}
string Data::getPoseFilePath() { return R"(../Data/ingredient_position_fill.csv)";}

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

vector<int> Data::getRecipe(string drink) {
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
		int pos = this->getPosition(ings[i]);
		for(int j = 0; j < quantity[i]; j++){
			positionQueue.push_back(pos);
		}
	}
	// Need position of ingredients
	// make queue of positions to visit
	// make quantities of how many times the drink needs to dispense 

	return positionQueue;
}
int Data::getPosition(int ing_idx){
	vector<int> ingredients;
	for (const vector<string>& row : this->fill_data) {
        if (row.size() >= 2) { // Ensure the row has at least two elements
            try {
                int value = stoi(row[1]); // Parse the second element as an integer
                ingredients.push_back(value);
            } catch (const std::invalid_argument& e) {
                // Handle the case where conversion to integer fails
                // For example, you could skip this row or log an error
            }
        }
    }

	for(int i = 0; i < ingredients.size(); i++){
        if (ingredients[i] == ing_idx){
            return i;
        }
    }
	return 0;
}
// returns of list of the drinks that can be made with the loaded ingredients
vector<string> Data::getActiveDrinkList() {
	vector<string> drinkList;
	for (const auto& row : this->df_menu) {
		string drink =row[0];
		bool flag = isDrinkMakable(row);
		if (flag) {
			drinkList.push_back(row[0]);
		}
		else {
		}
	}
	return drinkList;
}
// used by getActiveDrinkList to check if a drink from our menu is able to be made from the loaded ingredients
bool Data::isDrinkMakable(vector<string> recipie) {
	vector<string> ingredients = this->getColumn(this->fill_data, 1);
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

vector<string> Data::getColumn(vector<vector<string>> data, int colIdx) {
    vector<string> col;
    for (const auto& row : data) {
		col.push_back(row[colIdx]);
    }
    return col;
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


vector<string> Data::split_line(const string& line, char delimiter = ',')
{
    vector<string> result;
    stringstream ss(line);
    string token;

    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

int Data::append_CSV(string pose_value, string ingredient_value)
{
	string csv_filename = getPoseFilePath();
    string temp_filename = "temp.csv"; 
    string target_value = "Position 3";
    string fill_value = "100";

    ifstream input_file(csv_filename);
    ofstream output_file(temp_filename); // Temporary file

    // ... (Error handling for opening files)

    string line;
    while (getline(input_file, line)) {
        vector<string> fields = split_line(line);

        if (fields.size() >= 3 && fields[0] == pose_value)
        {
            fields[1] = to_string(this->ingredientToIndex(ingredient_value)); 
            fields[2] = fill_value;

            // Reconstruct the CSV line:
            output_file << fields[0];
            for (size_t i = 1; i < fields.size(); ++i)
            {
                output_file << "," << fields[i]; 
            }
            output_file << "\n"; 
        } 
        else 
        {
            output_file << line << "\n"; // Unmodified lines
        }
    }

    input_file.close();
    output_file.close();

    // Overwrite the original file
    remove(csv_filename.c_str()); 
    rename(temp_filename.c_str(), csv_filename.c_str());

	this->fill_data = getData(getPoseFilePath());

    return 0;
}

int Data::updateVolume(string bottle_position){

	string csv_filename = getPoseFilePath();
    string temp_filename = "temp.csv"; 

    ifstream input_file(csv_filename);
    ofstream output_file(temp_filename);
    string line;

	bottle_position = "Position " + bottle_position; 

	while (getline(input_file, line)) {
        istringstream iss(line);
        string pos, alcohol, amount;
        getline(iss, pos, ',');
        getline(iss, alcohol, ',');
        getline(iss, amount, ',');
        
        if (pos == bottle_position) {
            double currentAmount = stod(amount);
            double drinkPercent = (25.0 / 750.0) * 100.0;
            double newVolume = currentAmount - drinkPercent;
            if (newVolume < 0) {
                newVolume = 0; // Ensure the volume doesn't become negative
            }
            output_file << pos << "," << alcohol << "," << newVolume << endl;
            //cout << "Volume updated for position " << pos << endl;
        } else {
            output_file << line << endl;
        }
    }
    input_file.close();
    output_file.close();

	// Remove the original file and rename the temp file
    remove(csv_filename.c_str()); 
    rename(temp_filename.c_str(), csv_filename.c_str());

	this->fill_data = getData(getPoseFilePath());

	return 0;

}


bool Data::dataValidation(string drinkName) {
    //  get the recipe for the drink
    vector<int> recipe = getRecipe(drinkName);

    // Check if each ingredient's fill level is enough for the recipe
    for (int requiredIngredientIndex : recipe) {
        bool ingredientFound = false;
        int fillLevel = 0;

        // Find the required ingredient in the  csv fill file and compare the quantity
        for (const auto& row : this->fill_data) {
            if (stoi(row[1]) == requiredIngredientIndex) {
                ingredientFound = true;
                fillLevel = stoi(row[2]);
                break;
            }
        }

        // If the fill level is less that ingredient return false
        if ( fillLevel < ingredientFound) {
            return false;
        }
    }

    return true; 
}




#include <iostream>
#include <thread>
#include <vector>

#include "../Include/Data.h"
#include "../Include/SystemConfig.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"
#include "DataBaseUnitTest.h"


using namespace std;

void printDF(vector<vector<string>> df){
	for (const auto& row : df) {
		for (const auto& str : row) {	
			cout << str << "\t";
		}
		cout << endl;
	}
}
void printList(vector<string> list){
	for (const auto& str : list) {
		cout << str << endl;
	}
}
void printListOfInts(vector<int> list){
	for (const auto& str : list) {
		cout << str << "\t";
	}
	cout << endl;
}
void printColum(vector<vector<string>> list){
	for (const auto& str : list) {
		cout << str[1] << endl;
	}
}
void setIngredientPositions(Data *myData, SystemConfig *sys, vector<string> const *ingredients){
	int index = 0;
	for(auto& ing: *ingredients){
		int temp_ingredient_idx = myData->ingredientToIndex(ing);
		sys->updatePosition(index, temp_ingredient_idx);
		// cout << index << "\t" << temp_ingredient_idx << "\t" << ing << endl;
		index ++;
	}

}
void printSys(SystemConfig sys){
	for(auto& ing: sys.positions){
		cout << ing.getIngredient() << "\t" << ing.getPosition() << endl;
		// int a = 2, b = 4;
		// ing.setIngredient(a);
		// ing.setPosition(b);
		// cout << ing.ingredient << "\t" << ing.position << endl;

	}
}

vector<vector<int>> DataBaseExecutable(){
    Data* myData = new Data();
	SystemConfig* sys = new SystemConfig();
	Motor* myMotor = new Motor(1,2,3,4, 1.8);

	vector<vector<string>> df = myData->df_menu;
	vector<vector<string>> ing_df = myData->ingredient_indexes.df;
	vector<string> ing = myData->ingredient_indexes.ingredients;
	vector<string> idx = myData->ingredient_indexes.indexes;

	vector<string> system_ingredients = {"Vodka","Gin", "Cointreau", "Cranberry Juice", "Mezcal","Lime Juice"};
	setIngredientPositions(myData, sys, &system_ingredients);

	// printSys(*sys);

	string desired_drink = "Cosmopolitan";
	vector<int> drink_queue = myData->getRecipe(desired_drink, *sys);

	vector<int> step_queue = myMotor->getStepQueue(drink_queue);

	vector<vector<int>> queues;
	queues.push_back(step_queue);
	queues.push_back(drink_queue);

	// printListOfInts(drink_queue);
	// printListOfInts(step_queue);
	return queues;

}
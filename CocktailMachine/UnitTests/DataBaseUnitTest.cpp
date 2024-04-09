#include <iostream>
#include <thread>
#include <vector>

#include "../Include/Data.h"
// #include "../Include/SystemConfig.h"
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

int DataBaseExecutable(){
    Data* myData = new Data();


	vector<vector<string>> df = myData->df_menu;
	vector<vector<string>> ing_df = myData->ingredient_indexes.df;
	vector<string> ing = myData->ingredient_indexes.ingredients;
	vector<string> idx = myData->ingredient_indexes.indexes;
	vector<vector<string>> fill_df = myData->fill_data;

	string desired_drink = "Cosmopolitan";
	vector<string> drinkList = myData->getActiveDrinkList();
	vector<int> drink_queue = myData->getRecipe(desired_drink);
	printList(drinkList);
	printListOfInts(drink_queue);
	// cout << "HELLO" <<endl;


	
	return 0;
}
#include <iostream>
#include "Include/Data.h"
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

void printColum(vector<vector<string>> list){
	for (const auto& str : list) {
		cout << str[1] << endl;
	}
}
int main(){

	Data* myData = new Data();
	vector<vector<string>> df = myData->df_menu;
	vector<vector<string>> ing_df = myData->ingredient_indexes.df;
	vector<string> ing = myData->ingredient_indexes.ingredients;
	vector<string> idx = myData->ingredient_indexes.indexes;
	cout << ing.size() << endl;
	cout << idx.size() << endl;
	//printColum(ing_df);
	//printList(ing);
	//cout << endl;
	//printList(idx);
	return 0;
}

#include <iostream>
#include "Include/Data.h"
using namespace std;

void printList(vector<vector<string>> df){
	for (const auto& row : df) {
		for (const auto& str : row) {	
			cout << str << "\t";
		}
		cout << endl;
	}
}
int main(){

	Data* myData = new Data();
	vector<vector<string>> df = myData->df_menu;
	printList(df);
	cout << "Hello Cmake" << endl;
	return 0;
}

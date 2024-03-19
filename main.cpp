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
	string desired_drink = "Cosmopolitan";
	vector<vector<string>> drink_data = myData->getRecipe(desired_drink);
	printDF(drink_data);
	return 0;
}

// int main(){
// MOTOR TEST
// }


// #include<iostream>
// #include "SWITCH_CONTROL_H.h"
// #include <iostream>
// #include  <pigpio.h>
// #include  <thread>

// void switchMonitor (int switchIndex, SwitchControl& switchControl){
//      while (true) {
//         if (switchControl.isSwitchOn(switchIndex)){
//             std::cout<<"Switch "<<switchIndex+1<<"IS ON/n";
//         }else {
//             std::cout<<"Switch "<<switchIndex+1<<"IS OFF/n";
//         }
//      }
//  }
    
    


// int main() {
    
//      std::vector<int>SwitchPins = {7,13,15};
//      SwitchControl switchControl (SwitchPins);

//      if(!switchControl.intialize()){
//         std::cout<<"initialization failed.\n";
//         return 1;
//      }
//      std::vector<std::thread> threads;
//      for (int i= 0; i < SwitchPins.size();i++){
//          threads.emplace_back(switchMonitor , i, std::ref(switchControl));
//      }
//      //waiting for the threads to finish of which it never does
//      for(std::thread& t:threads) {
//          t.join();
//      }
     
     

//     return 0;

// }



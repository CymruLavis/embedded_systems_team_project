#ifndef DATA_BASE_UNIT_TEST_H
#define DATA_BASE_UNIT_TEST_H

#include <iostream>
#include <thread>
#include <vector>

#include "../Include/Data.h"
#include "../Include/SystemConfig.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"

void printDF(vector<vector<string>> df);
void printList(vector<string> list);
void printListOfInts(vector<int> list);
void printColum(vector<vector<string>> list);
void setIngredientPositions(Data *myData, SystemConfig *sys, vector<string> const *ingredients);
void printSys(SystemConfig sys);
int DataBaseExecutable();


#endif
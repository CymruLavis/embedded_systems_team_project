#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <vector> 

using namespace std;

class Ingredient {
public:
	string ingredient;
	int fillLevel;
	int position;
	
	string getIngredient();
	void setIngredient(string ingred);

	int getFillLevel();
	void setFillLevel(int level);

	int getPosition();
	void setPosition(int pos);
	
};

#endif

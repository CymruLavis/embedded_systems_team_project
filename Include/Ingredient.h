#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>

using namespace std;

class Ingredient {
public:
	string ingredient;
	int fillLevel;
	int position;
	
	Ingredient(string ing, int pos);
	string getIngredient();
	void setIngredient(string ingred);

	int getFillLevel();
	void setFillLevel(int level);

	int getPosition();
	void setPosition(int pos);
	
};

#endif

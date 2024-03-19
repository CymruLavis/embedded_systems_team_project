#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <vector> 

using namespace std;

class Ingredient {
public:
	int ingredient;
	double fillLevel;
	int position;
	Ingredient(int ing, int pos);

	int getIngredient();
	void setIngredient(int ingred);

	int getFillLevel();
	void setFillLevel(int level);
	void resetFillLevel();
	void takeADrink();

	int getPosition();
	void setPosition(int pos);
	
};

#endif

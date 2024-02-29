#include <iostream>
#include <vector>
#include <string>

class Ingredient {
public:
	string ingredient;
	int fillLevel;
	int position;
	
	Ingredient(string ing, int pos) {
		this->setFillLevel(100);
		this->setIngredient(ing);
		this->setPosition(pos);
	}

	string getIngredient() {return this->ingredient;}
	void setIngredient(string ingred) {this->ingredient = ingred;}

	int getFillLevel() {return this->fillLevel;}
	void setFillLevel(int level) {this->fillLevel = level;}
	
	int getPosition() {return this->position;}
	void setPosition(int pos) {this->position = pos;}
};

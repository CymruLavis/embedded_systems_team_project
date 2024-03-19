#include <iostream>
#include <vector>
#include <string>

#include "../Include/Ingredient.h"

using namespace std;
	
Ingredient::Ingredient(int ing, int pos) {
	this->setFillLevel(100.0);
	this->setIngredient(ing);
	this->setPosition(pos);
}

int Ingredient::getIngredient() {return this->ingredient;}
void Ingredient::setIngredient(int ingred) {this->ingredient = ingred;}

int Ingredient::getFillLevel() {return this->fillLevel;}
void Ingredient::setFillLevel(int level) {this->fillLevel = level;}

int Ingredient::getPosition() {return this->position;}
void Ingredient::setPosition(int pos) {this->position = pos;}

void Ingredient::resetFillLevel(){this->fillLevel = 100.0;}
void Ingredient::takeADrink(){
	double percentage_per_drink = 25/750;
	this->fillLevel = this->fillLevel - percentage_per_drink;
}

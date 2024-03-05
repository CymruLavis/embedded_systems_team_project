#include <iostream>
#include <vector>
#include <string>

#include "../Include/Ingredient.h"

using namespace std;
	
Ingredient::Ingredient(string ing, int pos) {
	this->setFillLevel(100);
	this->setIngredient(ing);
	this->setPosition(pos);
}

string Ingredient::getIngredient() {return this->ingredient;}
void Ingredient::setIngredient(string ingred) {this->ingredient = ingred;}

int Ingredient::getFillLevel() {return this->fillLevel;}
void Ingredient::setFillLevel(int level) {this->fillLevel = level;}

int Ingredient::getPosition() {return this->position;}
void Ingredient::setPosition(int pos) {this->position = pos;}

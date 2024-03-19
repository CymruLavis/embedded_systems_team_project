#include "../Include/SystemConfig.h"
#include "../Include/Ingredient.h"

#include <iostream>
#include <vector>
#include <array>


void SystemConfig::updatePosition(int index, int new_ingredient){
    this->positions[index].ingredient = new_ingredient;
    this->positions[index].resetFillLevel();

}

Ingredient SystemConfig::getIngredient(int index){
    return this->positions[index];
}
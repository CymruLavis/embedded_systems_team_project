#include "../Include/SystemConfig.h"
#include "../Include/Ingredient.h"

#include <iostream>
#include <vector>
#include <array>


void SystemConfig::updatePosition(int index, int new_ingredient){
    this->positions[index].setIngredient(new_ingredient);
    this->positions[index].resetFillLevel();
    this->positions[index].setPosition(index);
}
Ingredient SystemConfig::getIngredient(int index){
    return this->positions[index];
}
int SystemConfig::getPosition(int drink_idx){

    for(int i = 0; i < this->positions.size(); i++){
        if (this->positions[i].ingredient == drink_idx){
            return i;
        }
    }
    return 0;
}

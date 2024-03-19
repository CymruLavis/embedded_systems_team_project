#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "Ingredient.h"

#include <iostream>
#include <vector>
#include <array>

using namespace std;
class SystemConfig {
public:
    static array<Ingredient, 6> positions;
    void updatePosition(int index, int new_ingredient);

    Ingredient getIngredient(int index);
};
#endif
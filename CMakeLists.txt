cmake_minimum_required(VERSION 3.0)
project(cocktail_machine)

include_directories(include)
include_directories(src)

add_executable(cocktail_machine 
                main.cpp 
                src/DataClass.cpp 
                src/IngredientIndexClass.cpp 
                src/IngredientClass.cpp
                src/SystemConfig.cpp)

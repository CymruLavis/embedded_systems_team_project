cmake_minimum_required(VERSION 3.0)
project(cocktail_machine)

include_directories(include)
include_directories(src)

add_executable(cocktail_machine 
                main.cpp 
                src/DataClass.cpp 
                src/IngredientIndexClass.cpp 
                src/IngredientClass.cpp)

find_path(pigpio_INCLUDE_DIR 
NAMES pigpio.h pigpiod_if.h pigpiod_if2.h
HINTS /usr/local/include)

target_link_libraries(cocktail_machine pigpio)

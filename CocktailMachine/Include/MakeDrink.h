#ifndef MAKE_DRINK_H
#define MAKE_DRINK_H
#include <string>
#include "../Include/Motor.h"


class MakeDrink{
public:
    MakeDrink();
    void initializePins();
    void Make_a_drink_thread(string& DrinkName);
    int Make_a_drink(string DrinkName);
    
    Motor* carousel_motor = new Motor(21,20,16,12, 2.25);  // Physical pins 40,38,36,32
    Motor* riser_motor = new Motor(13,6,5,0,2.7);

    int GPIO_LIMIT_SWITCH_TOP; // physical 35
    int GPIO_LIMIT_SWITCH_BOTTOM; // physical 37

    int GPIO_ZERO_SWITCH; // 16 
    int GPIO_LIGHTGATE;  // 28
    int GPIO_PIR;

};

#endif
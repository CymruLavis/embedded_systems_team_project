#include "../Include/Interrupt.h"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <pigpio.h>
#include <vector>
#include <chrono>

#include "../src/MakeDrink.cpp"

volatile bool inting = 0;

using namespace std;

void Interrupt::displayInterrupt(int gpio, int edge, uint32_t tick)
{
    if(inting == 0){
        cout << "Interrupted" << endl;
        time_sleep(1);

        //gpioWrite(15, PI_HIGH); //gpio of vertical motor enable
        //gpioWrite(18, PI_HIGH); //gpio of carousel motor enable

        std::cout << "Motor pin turned off." << std::endl;
        inting = 1;
    }

}
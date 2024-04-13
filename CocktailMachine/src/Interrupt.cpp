#include "../Include/Interrupt.h"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <pigpio.h>
#include <vector>

volatile bool inting = 0;

using namespace std;

void Interrupt::displayInterrupt(int gpio, int edge, uint32_t tick)
{
    if(inting == 0){
        cout << "Interrupted" << endl;
        time_sleep(1);
        inting = 1;
    }

}
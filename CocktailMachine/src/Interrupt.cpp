#include "../Include/Interrupt.h"

#include <iostream>
#include <thread>
#include <typeinfo>
#include <pigpio.h>
#include <vector>

using namespace std;

void Interrupt::displayInterrupt(int gpio, int edge, uint32_t tick)
{
    cout << "Interrupted" << endl;
    time_sleep(60);
}
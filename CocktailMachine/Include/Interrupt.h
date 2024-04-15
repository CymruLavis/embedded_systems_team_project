#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <iostream>
#include <thread>
#include <typeinfo>
#include <pigpio.h>
#include <vector>

using namespace std;

class Interrupt{

    public:
        static void displayInterrupt(int gpio, int level, uint32_t tick);

};

#endif
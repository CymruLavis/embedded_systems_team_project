#ifndef SWITCH_CONTROL_H
#define SWITCH_CONTROL_H

#include <iostream>
#include  <pigpio.h>
#include  <vector>

class SwitchControl {
    public:
     SwitchControl(std::vector<int>pins);
     bool intialize();
     bool isSwitchOn(int index);
    private:
      std::vector<int>switchPins;


};

#endif

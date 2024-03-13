#include "SWITCH_CONTROL_H.h"
#include <iostream>
#include  <pigpio.h>


SwitchControl::SwitchControl(std::vector<int>pins) :switchPins(pins) {}


//initializes the gpio pin
bool SwitchControl::intialize() {
    if (gpioInitialise()< 0){
        std::cout<<"unable to intialize to pigpio.\n";
        return false;
    }
    for(int Pin:switchPins){
    gpioSetMode(Pin, PI_INPUT);
     }
    return true;
}
//checks if the switchs is on 
bool SwitchControl::isSwitchOn(int index) {
    if (index < 0 ){
        if (index >= switchPins.size()){
        std::cout<<"invalid index.\n";
        return false;
       }
      }
    return gpioRead(switchPins[index]) == 1;


}


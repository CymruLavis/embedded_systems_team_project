#include "../Include/LimitSwitch.h"
#include <iostream>
#include <pigpio.h>

using namespace std;

LimitSwitch::LimitSwitch(int pin){
	this->setPin(pin);
	gpioSetMode(pin, PI_INPUT);
	// if (gpioInitialise()< 0){
    //     std::cout<<"unable to intialize to pigpio.\n";
    // }
}
int LimitSwitch::getPin(){
	return this->pin;
}
void LimitSwitch::setPin(int p){
	this->pin = p;
}
// int LimitSwitch::getState(){
// 	return this->state;
// }
// void LimitSwitch::setState(int s){
// 	this->state = s;
// }
// void LimitSwitch::changeState(){
// 	int currentState = this->getState();
// 	if(currentState == 0){
// 		this->setState(1);
// 	}
// 	else{
// 		this->setState(0);
// 	}
	
// }
bool LimitSwitch::intialize() {
    if (gpioInitialise()< 0){
        std::cout<<"unable to intialize to pigpio.\n";
        return false;
    }
    for(int Pin:switchPins){
    	gpioSetMode(Pin, PI_INPUT);
	}
    return true;
}

//initializes the gpio pin

//checks if the switchs is on 
bool LimitSwitch::isSwitchOn(int index) {
    if (index < 0 ){
        if (index >= switchPins.size()){
        std::cout<<"invalid index.\n";
        return false;
       }
      }
    return gpioRead(switchPins[index]) == 1;

}

bool LimitSwitch::pirSensorThread() {
    
	// If motion is detected, print a message
	if (gpioRead(this->getPin()) == PI_HIGH) {
		return true;
	}
	else
		return false;
	time_sleep(0.05);

}
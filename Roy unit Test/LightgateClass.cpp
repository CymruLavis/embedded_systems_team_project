#include "../Include/LightGate.h"
#include <iostream>
#include <pigpio>

using namespace std;

LightGate::LightGate(int pin) : lightGateSwitchPin(pin) {}


int LightGate::getPin(){
	return lightGateSwitchPin;
}
void LightGate::setPin(int p){
	lightGateSwitchPin = p;
}
int LightGate::getState(){
	return state;
}
void LightGate::setState(int s){
	state = s;
}

//initialize the light gate gpio pin 
bool LightGate::initialize(){
	if(gpioInitialise() < 0) {
        cout<<"Not initialized.\n"
		return false;
	}else{
		gpioSetMode( lightGateSwitchPin,PI_INPUT);// Set the GPIO pin as an input
	return true;

	}
}
 // Read the state of the GPIO pin (HIGH/on or Low/off) prints it for confirmation then  return it

bool LightGate::returnState(){

	if(gpioRead(lightGateSwitchPin));{
		cout<<"light gate switch is on.\n";
		return true;
	}else{
		cout<<"Light gate switch is off.\n";
	return false;
	}
	
	
}

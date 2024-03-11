#include "../Include/LimitSwitch.h"
#include <iostream>

using namespace std;

LimitSwitch::LimitSwitch(int pin){
	this->setPin(pin);
}
int LimitSwitch::getPin(){
	return this->pin;
}
void LimitSwitch::setPin(int p){
	this->pin = p;
}
int LimitSwitch::getState(){
	return this->state;
}
void LimitSwitch::setState(int s){
	this->state = s;
}
void LimitSwitch::changeState(){
	int currentState = this->getState();
	if(currentState == 0){
		this->setState(1);
	}
	else{
		this->setState(0);
	}
}

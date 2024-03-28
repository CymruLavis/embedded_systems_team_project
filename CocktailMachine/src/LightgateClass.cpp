#include "../Include/LightGate.h"
#include <iostream>

using namespace std;

int LightGate::getPin(){
	return this->pin;
}
void LightGate::setPin(int p){
	this->pin = p;
}
int LightGate::getState(){
	return this->state;
}
void LightGate::setState(int s){
	this->state = s;
}
void LightGate::changeState(){
	int currentState = this->getState();
	if(currentState == 0){
		this->setState(1);
	}
	else{
		this->setState(0);
	}
}

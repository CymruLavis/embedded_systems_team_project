#ifndef LIGHT_GATE_H
#define LIGHT_GATE_H

#include <iostream>

using namespace std;

class LightGate{
	int pin;
	int state;
	
	int getPin();
	void setPin(int p);
	int getState();
	void setState(int s);
	void changeState();
	
};
#endif

#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <iostream>

using namespace std;

class LimitSwitch{
public:
	int pin;
	int state;
	
	int getPin();
	void setPin(int p);
	int getState();
	void setState(int s);
	void changeState();
};


#endif

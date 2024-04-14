#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <iostream>
#include  <pigpio.h>
#include  <vector>

class PIRSensor;

using namespace std;

class LimitSwitch{
public:
	int pin;
	int state;
	vector<int> switchPins;

	LimitSwitch(int pin);
	int getPin();
	void setPin(int p);
	int getState();
	void setState(int s);
	void changeState();
	bool intialize();
	bool isSwitchOn(int index);
	bool pirSensorThread();


};


#endif
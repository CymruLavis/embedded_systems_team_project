#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>

using namespace std;

class Motor{
public:
	int direction_pin;
	int step_pin;
	int sleep_pin;
	int fault_pin;
	
	Motor(int dir, int step, int sleep, int fault);
	
	void setDirPin(int pin);
	int getDirPin();
	void setStepPin(int pin);
	int getStepPin();
	void setSleepPin(int pin);
	int getSleepPin();
	void setFaultPin(int pin);
	int getFaultPin();
};

#endif

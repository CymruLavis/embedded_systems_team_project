#ifndef LIGHT_GATE_H
#define LIGHT_GATE_H
#include <iostream>



using namespace std;

class LightGate{
public:
    LightGate(int switchPin); 
	bool initialize();
	bool returnState();

	int getPin();
	void setPin(int p);
	int getState();
	void setState(int s);
	
private:
    int lightGateSwitchPin;

	
};
#endif

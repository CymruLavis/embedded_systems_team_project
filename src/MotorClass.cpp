#include <iostream>

#include "../Include/Motor.h"

Motor::Motor(int dir, int step, int sleep, int fault){
	Motor::setDirPin(dir);
	Motor::setStepPin(step);
	Motor::setSleepPin(sleep);
	Motor::setFaultPin(fault);
}
void Motor::setDirPin(int pin)	{
	this->direction_pin = pin;
}
int Motor::getDirPin(){
	return this->direction_pin;
}
void Motor::setStepPin(int pin)	{
	this->step_pin = pin;
}
int Motor::getStepPin(){
	return this->step_pin;
}
void Motor::setSleepPin(int pin)	{
	this->sleep_pin = pin;
}
int Motor::getSleepPin(){
	return this->sleep_pin;
}
void Motor::setFaultPin(int pin)	{
	this->fault_pin = pin;
}
int Motor::getFaultPin(){
	return this-> fault_pin;
}


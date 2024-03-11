#include "../Include/Motor.h"
#include <pigpio.h>

#include <iostream>
#include <unistd.h>

Motor::Motor(int dir, int step, int sleep, int fault, double step_size){
    Motor::setDirPin(dir);
    Motor::setStepPin(step);
    Motor::setSleepPin(sleep);
    Motor::setFaultPin(fault);
	Motor::initializePins(dir, step, sleep, fault);

	Motor::step_angle = step_size;
	Motor::setMotorCharacteristics(Motor::step_angle);


}
void Motor::setMotorCharacteristics(double step_angle){
	this->step_per_rev = 360/step_angle;
}
void Motor::setDirPin(int pin){
    this->direction_pin = pin;
}
int Motor::getDirPin(){
    return this->direction_pin;
}
void Motor::setStepPin(int pin){
    this->step_pin = pin;
}
int Motor::getStepPin(){
    return this->step_pin;
}
void Motor::setSleepPin(int pin){
    this->sleep_pin = pin;
}
int Motor::getSleepPin(){
    return this->sleep_pin;
}
void Motor::setFaultPin(int pin){
    this->fault_pin = pin;
}
int Motor::getFaultPin(){
    return this->fault_pin;
}

void Motor::setDirState(int val){
    this->dir_state = val;
}
int Motor::getDirState(){
    return this->dir_state;
}
void Motor::setStepState(int val){
    this->step_state = val;
}
int Motor::getStepState(){
    return this->step_state;
}
void Motor::setSleepState(int val){
    this->sleep_state = val;
}
int Motor::getSleepState(){
    return this->sleep_state;
}
void Motor::setFaultState(int val){
    this->fault_state=val;
}
int Motor::getFaultState(){
    return this->fault_state;
}
void Motor::setStepPerRev(int val){
    this->step_per_rev = val;
}
int Motor::getStepPerRev(){
    return this->step_per_rev;
}
void Motor::setStepAngle(double val){
    this->step_angle = val;
}
double Motor::getStepAngle(){
    return this->step_angle;
}
void Motor::initializePins(int dir, int step, int sleep, int fault){
    gpioSetMode(dir, PI_OUTPUT);
    gpioSetMode(step, PI_OUTPUT);
    gpioSetMode(sleep, PI_OUTPUT);
    gpioSetMode(fault, PI_OUTPUT);

}
void Motor::step(){
    gpioWrite(this->getStepPin(), 1);
    usleep(1000);
    gpioWrite(this->getStepPin(), 0);
    usleep(1000);
}

int Motor::decideDirection(int currentPos, int desiredPos){
	return 0;
}
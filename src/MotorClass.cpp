#include "../Include/Motor.h"
#include <pigpio.h>

#include <iostream>
#include <unistd.h>
#include <vector>
#include <math>

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

int Motor::getDistanceBetweenPositions(int currentPos, int desiredPos){

    int distanceBetweenPostion = std::abs(currentPos-desiredPos);
    
    return distanceBetweenPostion;

}
double Motor::getDegreesToSpin(int distanceBetweenPositions){
   double degreesToSpin = distanceBetweenPositions * 60; 
    return degreesToSpin;

}
int Motor::getStepsToRotoate(double degreesToSpin){
    double step_angle = this->getStepAngle();
    int steps = degreesToSpin/step_angle;

    return steps;

}

vector<int> Motor::getStepQueue(vector<int> positionQueue){
    vector<int> step_queue;
    int currentPos = 0;
    for(int i = 0; i < positionQueue.size(); i++){
        int dist = Motor::getDistanceBetweenPositions(currentPos, positionQueue[i]);
        double deg_to_rototae = Motor::getDegreesToSpin(dist);
        int steps = Motor::getStepsToRotoate(deg_to_rototae);
        step_queue.push_back(steps);
        currentPos = positionQueue[i];
    }

    return step_queue;
}
#include "../Include/Motor.h"
#include <pigpio.h>

#include <iostream>
#include <unistd.h>

#include <cstdlib>
#include <cmath>
#include <algorithm>

#include <vector>

Motor::Motor(const vector<int>& directions, const vector<int>& posits,const vector<int>& verts, int degrees, int direc, int dir, int step, int sleep, int fault){
    //MAIN RUN: input a vector of degree's and vector of vertical flags
    //FIRST THE FUNCTION WILL PARSE VERTS AND CALL VERRT_TURN WHEN VERTS VECTOR =1
    //THEN IT WILL PARSE THE FIRST VALUE OF POSITS AND PASS THAT TO THE MAIN_TURN, 
    //MAIN TURN WILL EXECUTE
    // A TURN AND THEN RETURN A 1 UPON SUCCESS.
    // THE SYSTEM WILL THEN LOOP THROUGH THE VECTORS
    Motor::MOTORS_RUN(directions, posits, verts); 
    Motor::MAIN_TURN(direc, degrees); //inputs:degrees, output:success
    Motor::VERT_TURN(); //input nothing, just call it and it runs, output: int success


    Motor::setDirPin(dir);
    Motor::setStepPin(step);
    Motor::setSleepPin(sleep);
    Motor::setFaultPin(fault);
	Motor::initializePins(dir, step, sleep, fault);

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

void Motor::initializePins(int dir, int step, int sleep, int fault){
    gpioSetMode(dir, PI_OUTPUT);
    gpioSetMode(step, PI_OUTPUT);
    gpioSetMode(sleep, PI_OUTPUT);
    gpioSetMode(fault, PI_INPUT);

}

int Motor::MOTORS_RUN(const vector<int>& directions, const std::vector<int>& posits, const std::vector<int>& verts){ //input a vector of degree's and vector of vertical flags

} 
int Motor::MAIN_TURN(int direc, int degrees){ //inputs:degrees, output:success

} 
int Motor::VERT_TURN(){//input nothing, just call it and it runs, output: int success

} 


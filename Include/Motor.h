#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <vector>

using namespace std;

class Motor{
public:
    Motor(const vector<int>& directions, const vector<int>& posits,const vector<int>& verts, int degrees, int direc, int dir, int step, int sleep, int fault);
    
    int MOTORS_RUN(const vector<int>& directions, const std::vector<int>& posits, const std::vector<int>& verts); //input a vector of degree's and vector of vertical flags
    int MAIN_TURN(int direc, int degrees); //inputs:degrees, output:success
    int VERT_TURN(); //input nothing, just call it and it runs, output: int success


    void setDirPin(int pin);
    int getDirPin();
    void setStepPin(int pin);
    int getStepPin();
    void setSleepPin(int pin);
    int getSleepPin();
    void setFaultPin(int pin);
    int getFaultPin();

    void setDirState(int val);
    int getDirState();
    void setStepState(int val);
    int getStepState();
    void setSleepState(int val);
    int getSleepState();
    void setFaultState(int val);
    int getFaultState();

    void initializePins(int dir, int step, int sleep, int fault);


    // Pin out
    int direction_pin;  //1 = clockwise; 0 = counter clockwise
    int step_pin;
    int sleep_pin;
    int fault_pin;

    // pin states
    int dir_state;
    int step_state;
    int sleep_state;
    int fault_state;

};

#endif
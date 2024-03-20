#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <vector>


using namespace std;

class Motor{
public:
    Motor(int dir, int step, int sleep, int fault, double step_angle);

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

    void setStepPerRev(int val);
    int getStepPerRev();
    void setStepAngle(double val);
    double getStepAngle();

    void initializePins(int dir, int step, int sleep, int fault);
	void setMotorCharacteristics(double step_angle);
    int decideDirection(int currentPos, int desiredPos);
    void step();

    int getDistanceBetweenPositions(int currentPos, int desiredPos);
    double getDegreesToSpin(int distanceBetweenPositions);
    int getStepsToRotoate(double degreesToSpin);

    vector<int> getStepQueue(vector<int> positionQueue);    
    

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

    // Motor Characteristics
    int step_per_rev;
    double step_angle;
    int clockwise = 1;
    int counterClockwise = 0;
};

#endif
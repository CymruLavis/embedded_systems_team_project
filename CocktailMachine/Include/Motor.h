#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <vector>


using namespace std;

class Motor{
public:
    Motor(int dir, int step, int sleep, int fault, int enable);
   
    void setDirPin(int pin);
    int getDirPin();

    void setStepPin(int pin);
    int getStepPin();

    void setSleepPin(int pin);
    int getSleepPin();

    void setFaultPin(int pin);
    int getFaultPin();

    void setEnPin(int pin);
    int getEnPin();

    void initializePins(int dir, int step, int sleep, int fault, int enable);

    void Enable_Motors();
    void Disable_Motors();
    void IsFaulty();

    vector<int> getStepQueue(vector<int> positionQueue);
    vector<double> calculateTimeIntervals(int steps, double t_end);    
    void VERT_MOVE(const int &upper_switch, const int &lower_switch);
    void motor_go(bool clockwise, int steps, const int &LIGHTGATE);
    void MAIN_MOTOR_RESET(const int &calibration_switch, const int &LIGHTGATE);

    // Pin out
    int direction_pin;  //1 = clockwise; 0 = counter clockwise
    int step_pin;
    int sleep_pin;
    int fault_pin;
    int enable_pin;

    // // pin states
    // int dir_state;
    // int step_state;
    // int sleep_state;
    // int fault_state;

    // Motor Characteristics
    //int step_per_rev;
    //double step_angle;
    //int clockwise = 1;
    //int counterClockwise = 0;
};

#endif
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
	void setMotorCharacteristics(double step_angle);
    bool decideDirection(int steps);
    void changeDirection();
    void step();

    int getDistanceBetweenPositions(int currentPos, int desiredPos);
    double getDegreesToSpin(int distanceBetweenPositions);
    int getStepsToRotoate(double degreesToSpin);

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

    // pin states
    int dir_state;
    int step_state;
    int sleep_state;
    int fault_state;

};

#endif
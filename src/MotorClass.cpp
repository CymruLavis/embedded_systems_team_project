#include "../Include/Motor.h"
#include <pigpio.h>
#include <pigpiod_if2.h>

#include <iostream>
#include <unistd.h>
#include <vector>
#include <thread>

using namespace std;
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

void Motor::changeDirection(){
    if (this->getDirState() == 1){
        this->setDirPin(0);
    }
    else if(this->getDirState() == 0){
        this->setDirPin(1);
    }
}
bool Motor::decideDirection(int steps){
	if(steps>=0){
        return true;
    }
    else{
        return false;
    }
}

int Motor::getDistanceBetweenPositions(int currentPos, int desiredPos){

    int distanceBetweenPostion = currentPos-desiredPos;
    
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


void Motor::VERT_MOVE(LimitSwitch* upper_switch, LimitSwitch* lower_switch) {

        // Wake up the motor driver
        gpioWrite(this->getSleepPin(), PI_HIGH);

        // Set motor direction to up (assuming high means up)
        gpioWrite(this->getDirPin(), PI_HIGH);

        int up_steps = 300; // Define the number of steps to move up
        double stepdelay = 0.005; // Seconds between steps

        // Move up until hitting the top limit or completing the steps
        // for (int i = 0; i < up_steps; ++i) {
        while(upper_switch->getPin() == PI_LOW){
            
            if (gpioRead(upper_switch->getPin()) == PI_HIGH) {
                std::cout << "HIT THE TOP LIMIT\n";
                break; // Exit loop if top limit is reached
            }
            // if (gpioRead(FLT_pin) == PI_LOW) {
            //     gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
            //     throw std::runtime_error("MOTOR FAULT");
            // }
            gpioWrite(step_pin, PI_HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, PI_LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        }

        // Change direction to down (assuming low means down)
        this->changeDirection();

        // Move down until hitting the bottom limit
        // for (int i = 0; i < up_steps; ++i) {
        while(lower_switch->getPin() == PI_LOW){
            if (gpioRead(lower_switch->getPin()) == PI_HIGH) {
                std::cout << "HIT THE BOTTOM LIMIT\n";
                break; // Exit loop if bottom limit is reached
            }
            // if (gpioRead(FLT_pin) == PI_LOW) {
            //     gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
            //     throw std::runtime_error("MOTOR FAULT");
            // }
            gpioWrite(step_pin, PI_HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, PI_LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        }

        this->changeDirection();
        for(int i = 0; i < 2; i ++){
            this->step();
        }
        // Cleanup and put the motor driver in sleep mode
        gpioWrite(this->getSleepPin(), PI_LOW);
        cout <<"DONE" <<endl;
}


void Motor::motor_go(bool clockwise, double steps) {
        // Pin assignments

        // Set motor direction
        gpioWrite(this->getSleepPin(), PI_HIGH);

        gpioWrite(this->getDirPin(), clockwise ? PI_HIGH : PI_LOW);

        // Wake up the motor driver

        // Calculate steps from degrees (1.8 degrees per step)
        // int steps = static_cast<int>(degrees / 1.8);

        // Hardcoded delay values
        double stepdelay = 0.005; // Seconds between steps 0.002
        // this_thread::sleep_for(chrono::seconds(1));
        for (int i = 0; i < steps; ++i) {
            // Check for motor fault
            //if (gpioRead(FLT_pin) == PI_LOW) {
            //    gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
            //    throw std::runtime_error("MOTOR FAULT");
            //}

            // Perform a step
            gpioWrite(this->getStepPin(), PI_HIGH);
            std::cout << "HIGH...............\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(this->getStepPin(), PI_LOW);
            std::cout << "LOW..............\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            
        }   

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(this->getSleepPin(), PI_LOW);
    }

void Motor::MAIN_MOTOR_RESET(LimitSwitch* calibration_switch) {

    // Set motor direction to reset direction
    gpioWrite(this->getDirPin(), PI_HIGH);

    // Wake up the motor driver
    gpioWrite(this->getSleepPin(), PI_HIGH);

    // Assuming we do not know the exact steps needed to reset, use a large number
    // The loop will break once the zero position is detected

    // Hardcoded delay values
    double stepdelay = 0.005; // Seconds between steps

    while(gpioRead(calibration_switch->getPin()) == PI_LOW){
            // Check for motor fault
        // if (gpioRead(FLT_pin) == PI_LOW) {
        //     gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
        //     throw std::runtime_error("MOTOR FAULT");
        // }
        // Perform a step
        gpioWrite(step_pin, PI_HIGH);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        gpioWrite(step_pin, PI_LOW);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
    }

    // Cleanup and put the motor driver in sleep mode
    gpioWrite(this->getSleepPin(), PI_LOW);
}
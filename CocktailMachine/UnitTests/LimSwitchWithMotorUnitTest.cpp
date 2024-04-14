
#include "../Include/Motor.h"
#include "LimSwitchWithMotorUnitTest.h"
#include <pigpio.h>

#include <iostream>
#include <unistd.h>

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <thread>
#include <atomic>

#include <vector>

using namespace std;

#define Upper_switch 22 // GPIO pin for switch 1 physical pin 15
#define Lower_switch 27 // GPIO pin for switch 2 physical pin 13
#define Red_LED 5    // GPIO pin for LED 1 physical pin 29
#define Green_LED 6    // GPIO pin for LED 2 physical pin 31

// Global atomic booleans to control thread execution
std::atomic<bool> Motor_running(true);


void VERT_MOVE() {
        // Pin assignments
        int step_pin = 21; // Step pin
        int direction_pin = 20; // Direction pin for moving up/down
        int bottom_limit_pin = 19; // Bottom limit detection pin
        // int top_limit_pin = 20; // Top limit detection pin
        int FLT_pin = 16; // Fault detection pin
        int SLP_pin = 17; // Sleep mode pin

        // Initialize GPIO pins
        gpioSetMode(step_pin, PI_OUTPUT);
        gpioSetMode(direction_pin, PI_OUTPUT);
        gpioSetMode(bottom_limit_pin, PI_INPUT);
        // gpioSetMode(top_limit_pin, PI_INPUT);
        gpioSetMode(FLT_pin, PI_INPUT);
        gpioSetMode(SLP_pin, PI_OUTPUT);

        // Wake up the motor driver
        gpioWrite(SLP_pin, PI_HIGH);

        // Set motor direction to up (assuming high means up)
        gpioWrite(direction_pin, PI_HIGH);

        int up_steps = 300; // Define the number of steps to move up
        double stepdelay = 0.01; // Seconds between steps

        // Move up until hitting the top limit or completing the steps
        // for (int i = 0; i < up_steps; ++i) {
        while(Motor_running){
            
            if (gpioRead(Upper_switch) == PI_HIGH) {
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
        gpioWrite(direction_pin, PI_LOW);

        // Move down until hitting the bottom limit
        // for (int i = 0; i < up_steps; ++i) {
        while(Motor_running){
            if (gpioRead(Lower_switch) == PI_HIGH) {
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

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(SLP_pin, PI_LOW);
        cout <<"DONE" <<endl;
}

int LimSwitchAndMotorExecutable() {
    // Initialize pigpio library
    cout << "in executbale" << endl;
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    cout << "Initialized" << endl;
    // Set GPIO pins as input for switches and output for LEDs
    gpioSetMode(Upper_switch, PI_INPUT);
    gpioSetMode(Lower_switch, PI_INPUT);

    std::thread motorThread(VERT_MOVE);
    // Wait for user input to exit the program
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    // Stop the threads
    Motor_running = false;
    motorThread.join();

    // Cleanup: Uninitialize pigpio library
    gpioTerminate();

    return 0;
}
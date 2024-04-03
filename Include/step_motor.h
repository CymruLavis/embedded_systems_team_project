#include <iostream>
#include <pigpio.h>
#include <chrono>
#include <thread>
#include <stdexcept>

class DRV8825 {
public:
    void motor_go(bool clockwise, double degrees) {
        // Pin assignments
        int direction_pin = 8; // Direction pin
        int step_pin = 7; // Step pin
        int FLT_pin = 25; // Fault detection pin
        int SLP_pin = 1; // Sleep mode pin

        // Initialize GPIO pins
        gpioSetMode(direction_pin, PI_OUTPUT);
        gpioSetMode(step_pin, PI_OUTPUT);
        gpioSetMode(FLT_pin, PI_INPUT);
        gpioSetMode(SLP_pin, PI_OUTPUT);

        // Set motor direction
        gpioWrite(direction_pin, clockwise ? PI_HIGH : PI_LOW);

        // Wake up the motor driver
        gpioWrite(SLP_pin, PI_HIGH);

        // Calculate steps from degrees (1.8 degrees per step)
        float ratio = 30/20;
        float input = degrees * ratio;
        int steps = static_cast<int>(input / 1.8);

        // Hardcoded delay values
        double stepdelay = 0.005; // Seconds between steps 0.002
        this_thread::sleep_for(chrono::seconds(1));
        for (int i = 0; i < steps; ++i) {
            // Check for motor fault
            //if (gpioRead(FLT_pin) == PI_LOW) {
            //    gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
            //    throw std::runtime_error("MOTOR FAULT");
            //}

            // Perform a step
            gpioWrite(step_pin, 1);
            std::cout << "HIGH...............\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, 0);
            std::cout << "LOW..............\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            
        }   

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(SLP_pin, PI_LOW);
    }
    void MAIN_MOTOR_RESET() {
        // Pin assignments
        int direction_pin = 8; // Direction pin
        int step_pin = 7; // Step pin
        int FLT_pin = 15; // Fault detection pin
        int SLP_pin = 24; // Sleep mode pin
        int AXIS_ZERO_pin = 26; // Zero position detection pin

        // Initialize GPIO pins
        gpioSetMode(direction_pin, PI_OUTPUT);
        gpioSetMode(step_pin, PI_OUTPUT);
        gpioSetMode(FLT_pin, PI_INPUT);
        gpioSetMode(SLP_pin, PI_OUTPUT);
        gpioSetMode(AXIS_ZERO_pin, PI_INPUT);

        // Set motor direction to reset direction
        gpioWrite(direction_pin, 1);

        // Wake up the motor driver
        gpioWrite(SLP_pin, 1);

        // Assuming we do not know the exact steps needed to reset, use a large number
        // The loop will break once the zero position is detected

        int steps = 500; // Arbitrary large number

        // Hardcoded delay values
        double stepdelay = 0.005; // Seconds between steps

        for (int i = 0; i < steps; ++i) {
            // Check for motor fault
            //if (gpioRead(FLT_pin) == PI_LOW) {
            //    gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
            //    throw std::runtime_error("MOTOR FAULT");
            //}

            // Check for zero position
            if (gpioRead(AXIS_ZERO_pin) == 1) {
                std::cout << "System zero'd\n";
                break; // Exit loop if zero position is detected
            }

            // Perform a step
            gpioWrite(step_pin, 1);
            std::cout << "HIGH...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, 0);
            std::cout << "LOW...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            std::cout << gpioRead(AXIS_ZERO_pin);
            }

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(SLP_pin, 0);
        std::cout << "SYSTEM SET TO SLEEP\n";
    }

    void VERT_MOVE() {
        // Pin assignments
        int step_pin = 23; // Step pin
        int direction_pin = 18; // Direction pin for moving up/down
        int bottom_limit_pin = 19; // Bottom limit detection pin
        int top_limit_pin = 20; // Top limit detection pin
        int FLT_pin = 15; // Fault detection pin
        int SLP_pin = 24; // Sleep mode pin

        // Initialize GPIO pins
        gpioSetMode(step_pin, PI_OUTPUT);
        gpioSetMode(direction_pin, PI_OUTPUT);
        gpioSetMode(bottom_limit_pin, PI_INPUT);
        gpioSetMode(top_limit_pin, PI_INPUT);
        gpioSetMode(FLT_pin, PI_INPUT);
        gpioSetMode(SLP_pin, PI_OUTPUT);

        // Wake up the motor driver
        gpioWrite(SLP_pin, PI_HIGH);

        // Set motor direction to up (assuming high means up)
        gpioWrite(direction_pin, PI_HIGH);

        int up_steps = 300; // Define the number of steps to move up
        double stepdelay = 0.002; // Seconds between steps

        // Move up until hitting the top limit or completing the steps
        for (int i = 0; i < up_steps; ++i) {
            if (gpioRead(top_limit_pin) == PI_HIGH) {
                std::cout << "HIT THE TOP LIMIT\n";
                break; // Exit loop if top limit is reached
            }
            if (gpioRead(FLT_pin) == PI_LOW) {
                gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
                throw std::runtime_error("MOTOR FAULT");
            }
            gpioWrite(step_pin, PI_HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, PI_LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        }

        // Change direction to down (assuming low means down)
        gpioWrite(direction_pin, PI_LOW);

        // Move down until hitting the bottom limit
        for (int i = 0; i < up_steps; ++i) {
            if (gpioRead(bottom_limit_pin) == PI_HIGH) {
                std::cout << "HIT THE BOTTOM LIMIT\n";
                break; // Exit loop if bottom limit is reached
            }
            if (gpioRead(FLT_pin) == PI_LOW) {
                gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
                throw std::runtime_error("MOTOR FAULT");
            }
            gpioWrite(step_pin, PI_HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, PI_LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        }

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(SLP_pin, PI_LOW);
    }
};

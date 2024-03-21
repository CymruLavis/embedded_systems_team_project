#include <iostream>
#include <pigpio.h>
#include <chrono>
#include <thread>
#include <stdexcept>



class DRV8825 {
public:
    DRV8825() {
        // Initialize pigpio library
        if (gpioInitialise() < 0) {
            throw std::runtime_error("pigpio initialization failed");
        }
    }

    ~DRV8825() {
        // Terminate pigpio library
        gpioTerminate();
    }

    void motor_go(double degrees) {
        // Pin assignments
        int direction_pin = 20; // Direction pin
        int step_pin = 21; // Step pin
        int FLT_pin = 16; // Fault detection pin
        int SLP_pin = 17; // Sleep mode pin

        // Initialize GPIO pins
        gpioSetMode(direction_pin, PI_OUTPUT);
        gpioSetMode(step_pin, PI_OUTPUT);
        gpioSetMode(FLT_pin, PI_INPUT);
        gpioSetMode(SLP_pin, PI_OUTPUT);

        // Wake up the motor driver
        gpioWrite(SLP_pin, PI_HIGH);

        // Calculate steps from degrees (1.8 degrees per step)
        int steps = static_cast<int>(degrees / 1.8);

        // Hardcoded delay values
        double stepdelay = 0.005; // Seconds between steps

        for (int i = 0; i < steps; ++i) {
            // Check for motor fault
            if (gpioRead(FLT_pin) == PI_LOW) {
                gpioWrite(SLP_pin, PI_LOW); // Put the motor driver in sleep mode
                throw std::runtime_error("MOTOR FAULT");
            }

            // Perform a step
            gpioWrite(step_pin, PI_HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
            gpioWrite(step_pin, PI_LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(stepdelay * 1000)));
        }

        // Cleanup and put the motor driver in sleep mode
        gpioWrite(SLP_pin, PI_LOW);
    }
};

// Main function to demonstrate usage
int main() {
    std::cout << "TEST START\n";

    try {
        DRV8825 mymotor;
        // Example call: Rotate 180 degrees
        mymotor.motor_go(180);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "TEST END\n";
    return 0;
}

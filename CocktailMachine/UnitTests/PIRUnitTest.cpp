#include <iostream>
#include <thread>
#include <atomic>
#include <pigpio.h>

#include "../Include/LimitSwitch.h"
#include "PIRUnitTest.h"

LimitSwitch* PIR_Unit_Test_Sensor = new LimitSwitch(26); //physical pin 37

using namespace std;

std::atomic<bool> PIR_running(true);

void pirThread() {
    while (PIR_running) {
        // Read the current state of the PIR sensor
        PIR_Unit_Test_Sensor->pirSensorThread();
    }
}

int PIRExecutable(){
	cout << "Start" << endl;
	// Initialize the pigpio library	
    if (gpioInitialise() < 0) {
        cout << "pigpio initialization failed." << endl;
        return 1;
    }



	// gpioInitialise();
	cout << "Initialize physical pins" << endl;
	gpioSetMode(PIR_Unit_Test_Sensor->getPin(), PI_INPUT);
    
    // Create a thread to read the PIR sensor
    thread sensorThread(pirThread);
	cout << "in the thread" << endl;
    // // Wait for user input to exit the program
    cout << "Press Enter to exit." << endl;
    cin.get();

    // // Stop the sensor thread
    PIR_running = false;
    sensorThread.join();

    // // Uninitialize the pigpio library
	cout << "Terminate" << endl;
    gpioTerminate();
	return 0;
}


// Global variable to control whether the PIR thread should continue running
volatile bool PIR_running = true;

// PIR_Unit_Test_Sensor class for demonstration test of interrupt
class PIR_Unit_Test {
public:
    int getPin() { return 26; } // 37 actual pin
    void pirSensorThread() {
        //  PIR sensor detection
        if (gpioRead(getPin()) == 1) {
            std::cout << "Motion detected!" << std::endl;
            // Call a callback function to adjust the status of the motor pins
            adjustMotorPin(12,24);
        }
    }

    // Mock function to adjust the motor pin
    void adjustMotorPin(int motorPin1,int motorPin2 ) {
        std::cout << "Adjusting motor pin..." << std::endl;
        // Placeholder logic: Turn off motor controller GPIO pins
        gpioWrite(motorPin1, 0); 
        gpioWrite(motorPin2, 0); 
        std::cout << "Motor pin turned off." << std::endl;
        
    }
};

// Thread function to continuously read the PIR sensor
void pirThread(PIR_Unit_Test* PIR_Unit_Test_Sensor) {
    while (PIR_running) {
        // Read the current state of the PIR sensor
        PIR_Unit_Test_Sensor->pirSensorThread();
    }
}

// Main function
int PIRExecutable() {
    std::cout << "Start" << std::endl;

    // Initialize the pigpio library
    if (gpioInitialise() < 0) {
        std::cout << "pigpio initialization failed." << std::endl;
        return 1;
    }

    // Initialize physical pins
    std::cout << "Initialize physical pins" << std::endl;
    gpioSetMode(PIR_Unit_Test_Sensor->getPin(), PI_INPUT);

    // Create a PIR_Unit_Test instance
    PIR_Unit_Test* PIR_Unit_Test_Sensor = new PIR_Unit_Test();

    // Create a thread to read the PIR sensor
    std::thread sensorThread(pirThread, PIR_Unit_Test_Sensor);
    std::cout << "in the thread" << std::endl;

    // Wait for user input to exit the program
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    // Stop the sensor thread
    PIR_running = false;
    sensorThread.join();

    // Uninitialize the pigpio library
    std::cout << "Terminate" << std::endl;
    gpioTerminate();

    delete PIR_Unit_Test_Sensor; // Clean up allocated memory

    return 0;
}

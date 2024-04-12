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
void stopMotorAction(){

        gpioWrite(motorPin1, 0); //gpio of motor controller pin1
        gpioWrite(motorPin2, 0); //gpio of motor controller pin 2
        std::cout << "Motor pin turned off." << std::endl;

}

int PIRExecutable(){
	cout << "Start" << endl;
	// Initialize the pigpio library	
    if (gpioInitialise() < 0) {
        cout << "pigpio initialization failed." << endl;
        return 1;
    }
    
	
	gpioSetMode(PIR_Unit_Test_Sensor->getPin(), PI_INPUT);
    
    // Create a thread to read the PIR sensor
    thread sensorThread(pirThread);

    //set up ISR to stop the motor.
    gpioSetISRFunc(PIR_Unit_Test_Sensor->getPin(),RISING_EDGE,0,stopMotorAction);
    //gpio pin,the edge to be triggered,timeout,action when triggered.
    
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


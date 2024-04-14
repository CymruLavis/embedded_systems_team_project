#include <iostream>
#include <thread>
#include <atomic>
#include <pigpio.h>

#include "../Include/LimitSwitch.h"
#include "PIRUnitTest.h"

LimitSwitch* PIR_Unit_Test_Sensor = new LimitSwitch(26); //physical pin 37
LimitSwitch*led = new LimitSwitch(4);
using namespace std;

std::atomic<bool> PIR_running(true);

void pirThread() {
    while (PIR_running) {
        // Read the current state of the PIR sensor
        PIR_Unit_Test_Sensor->pirSensorThread();
    }
}
void lightLED(int gpio, int level, uint32_t tick){
        gpioSetMode(led->getPin(), PI_INPUT);
        std::cout << "Motion detected" << std::endl;

        gpioWrite(led->getPin(), 1); //gpio of motor controller pin1
        
        std::cout << "LED light on." << std::endl;

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
    gpioISRFunc_t myCallback = &lightLED;
    gpioSetISRFunc(PIR_Unit_Test_Sensor->getPin(),RISING_EDGE,0,myCallback);
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


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
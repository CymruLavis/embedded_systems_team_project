#include <pigpio.h>
#include <iostream>
#include "Include/Data.h"
#include "Include/step_motor.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {
    // Print to terminal
    cout << "Printing to terminal..." << endl;

    // Wait for 5 seconds
    this_thread::sleep_for(chrono::seconds(1));

    if (gpioInitialise() <0 ) {
        cout << "ERROR: Failed to initialize the GPIO interface." << endl;
        return 1;
        }

	try {
        DRV8825 mymotor;
        // Perform vertical movement between limits
        mymotor.motor_go(true, 90);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	gpioTerminate();
    std::cout << "TEST END\n";

    return 0;
}





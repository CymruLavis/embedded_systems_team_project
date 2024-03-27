
#include "LightgateUnitTest.h"
#include <iostream>
#include <pigpio.h>

// Constructor: Initialize with switch pin number
LimitGateSwitch::LimitGateSwitch(int switchPin)
    : switchPin_(switchPin), activated_(false) {}

// Start monitoring the switch
void LimitGateSwitch::startMonitoring() {
    // Initialize pigpio library
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return;
    }

    // Set GPIO pin as input for switch
    gpioSetMode(switchPin_, PI_INPUT);

    // Start monitoring the switch
    while (true) {
        if (gpioRead(switchPin_) == PI_LOW) {
            // Switch pressed
            std::cout << "Switch pressed" << std::endl;
            activated_ = true;
        } else {
            // Switch released
            activated_ = false;
        }
        
    }
}
// Stop monitoring the switch
void LimitGateSwitch::stopMonitoring() {
    // Cleanup: Uninitialize pigpio library
    gpioTerminate();
}

// Check if the switch is activated
bool LimitGateSwitch::isActivated() const {
    return activated_;
}

//int main (){
 // Initialize LimitGateSwitch instance with GPIO pin 16
   // LimitGateSwitch limitSwitch(16);

    // Start monitoring the switch
    //limitSwitch.startMonitoring();

    //return 0;

//};



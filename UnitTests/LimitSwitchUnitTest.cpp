#include <iostream>
#include <thread>
#include <atomic>
#include <pigpio.h>
#include "LimitSwitchUnitTest.h"
using namespace std;

// Define GPIO pins for limit switches and LEDs
#define SWITCH1_PIN 22 // GPIO pin for switch 1 physical pin 15
#define SWITCH2_PIN 27 // GPIO pin for switch 2 physical pin 13
#define Red_LED 5    // GPIO pin for LED 1 physical pin 29
#define Green_LED 6    // GPIO pin for LED 2 physical pin 31

// Global atomic booleans to control thread execution
std::atomic<bool> LimitSwitch_running(true);
// atomic<int> ledPin(0);


// Function to monitor switch and control LED
// void changeLEDStateCallback(int gpio, int level, uint32_t tick){
//     if (gpioRead(ledPin) == 1){
//         gpioWrite(ledPin, 0);
//     }
//     else{
//         gpioWrite(ledPin, 1);
//     }

// }


void aFunction(int gpio, int level, uint32_t tick)
{
   if(level == PI_HIGH){
    gpioWrite(Red_LED, PI_HIGH);
   }
   else{
    gpioWrite(Red_LED, PI_LOW);
   }
}

void monitorSwitch(int switchPin, int ledPin, const char* switchName) {
    while (LimitSwitch_running) {
        gpioSetAlertFunc(switchPin, aFunction);
        
        // if (gpioRead(switchPin) == PI_HIGH) {
        //     // Switch pressed, turn on LED
        //     std::cout << switchName << " pressed" << std::endl;
        //     gpioWrite(ledPin, PI_HIGH); // Turn on LED
        // } else {
        //     // Switch released, turn off LED
        //     gpioWrite(ledPin, PI_LOW); // Turn off LED
        // }
        time_sleep(0.1); // Delay for stability
    }
}

int LimitSwitchExecutable() {
    // Initialize pigpio library
    cout << "in executbale" << endl;
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    cout << "Initialized" << endl;
    // Set GPIO pins as input for switches and output for LEDs
    gpioSetMode(SWITCH1_PIN, PI_INPUT);
    gpioSetMode(SWITCH2_PIN, PI_INPUT);
    gpioSetMode(Red_LED, PI_OUTPUT);
    gpioSetMode(Green_LED, PI_OUTPUT);
    gpioWrite(Red_LED, PI_LOW);
    gpioWrite(Green_LED, PI_LOW);
    cout << "set pins" << endl;
    // Create threads to monitor switches and control LEDs
    std::thread switch1Thread(monitorSwitch, SWITCH1_PIN, Red_LED, "Switch 1");
    std::thread switch2Thread(monitorSwitch, SWITCH2_PIN, Green_LED, "Switch 2");
    // Wait for user input to exit the program
    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    // Stop the threads
    LimitSwitch_running = false;
    switch1Thread.join();
    switch2Thread.join();

    // Cleanup: Uninitialize pigpio library
    gpioTerminate();

    return 0;
}
        // gpioSetAlertFunc(switchPin, changeLEDStateCallback);

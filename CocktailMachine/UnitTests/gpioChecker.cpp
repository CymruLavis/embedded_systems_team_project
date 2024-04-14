#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <thread>
#include <atomic>
#include <vector>
#include "LogicTest.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"

using namespace std;

int GPIO_LIMIT_SWITCH_TOP = 19; // physical 35
int GPIO_LIMIT_SWITCH_BOTTOM =26; // physical 37

int GPIO_ZERO_SWITCH = 23; // 16 
int GPIO_LIGHTGATE = 1;  // 28
int GPIO_PIR = 22; // 15
//dir, step, sleep, fault, step_angle
Motor* carousel_motor = new Motor(21,20,16,12, 2.25);  // Physical pins 40,38,36,32
Motor* riser_motor = new Motor(13,6,5,0,2.7);    // Physical pins 33, 31,29,27

atomic<bool> system_running(true);
atomic<bool> program_running(true);

void initializePins(){
    carousel_motor->initializePins(carousel_motor->getDirPin(),
                                    carousel_motor->getStepPin(),
                                    carousel_motor->getSleepPin(),
                                    carousel_motor->getFaultPin());

    riser_motor->initializePins(riser_motor->getDirPin(),
                                riser_motor->getStepPin(),
                                riser_motor->getSleepPin(),
                                riser_motor->getFaultPin());

}

int gpioCheck(){
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    while(1){
 
        cout << "Bottom Limit Switch: " << gpioRead(GPIO_LIMIT_SWITCH_BOTTOM) << endl;
        cout << "Upper Limit Switch: " << gpioRead(GPIO_LIMIT_SWITCH_TOP) << endl;
        cout << "Calibration Switch: " << gpioRead(GPIO_ZERO_SWITCH) << endl;
        cout << "Light Gate:" << gpioRead(GPIO_LIGHTGATE) << endl;
        cout << "PIR: " << gpioRead(GPIO_PIR) << endl;

        cout << "Carousel Motor - dir, step, sleep, fault" << endl;
        cout << gpioRead(carousel_motor->getDirPin()) << "\t" << gpioRead(carousel_motor->getStepPin()) << "\t" << gpioRead(carousel_motor->getSleepPin()) << "\t" << gpioRead(carousel_motor->getFaultPin()) << endl;
        
        cout << "Riser Motor - dir, step, sleep, fault" << endl;
        cout << gpioRead(carousel_motor->getDirPin()) << "\t" << gpioRead(carousel_motor->getStepPin()) << "\t" << gpioRead(carousel_motor->getSleepPin()) << "\t" << gpioRead(carousel_motor->getFaultPin()) << endl;
    

        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(1)));

    }
    gpioTerminate();

    // terminate saftey thread (PIR and saftey switch)
    return 0;
}


// - make drink button/ saftey sensor and motor are activated
// - carousel motor starts/ light gate thread activate
// - light gate triggers/ carousel motor stops, riser motor starts
// - riser motor starts/ upper and lower limit swtich activate
// - either one of the switches are triggered/motor shuts off

// - threads must be joined back to their parent thread when they finish so utilize memory in the most effective way
// - this whole process will happen for every itteration of the drink ingredient queue

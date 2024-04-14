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
void makeDrinkThread(vector<int> queues){

            

            carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);
            bool clockwise=true;
            //carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);
            //riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM);
            for (int i = 0; i < 7; ++i) {
                carousel_motor->motor_go(clockwise, abs(200), GPIO_LIGHTGATE);
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(500)));
                riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM);   
            }
            
            clockwise=false;
            for (int i = 0; i < 3; ++i) {
                carousel_motor->motor_go(clockwise, abs(400), GPIO_LIGHTGATE);
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(2000)));   
            }


}


int LogicTestExecutable(){

    vector<int> queues = {0, 1, 2, 3, 4};

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }

    thread myThread(makeDrinkThread, ref(queues));
    
    cin.get();
    program_running = false;
    myThread.join();

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

/*
    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }

    gpioSetMode(GPIO_LIMIT_SWITCH_BOTTOM, PI_INPUT);
    gpioSetMode(GPIO_LIMIT_SWITCH_TOP, PI_INPUT);
    gpioSetMode(GPIO_ZERO_SWITCH, PI_INPUT);
    gpioSetMode(GPIO_LIGHTGATE, PI_INPUT);
    int i = 0;
    while(1){
        cout << "Bottom Limit Switch: " << gpioRead(GPIO_LIMIT_SWITCH_BOTTOM) << endl;
        cout << "Upper Limit Switch: " << gpioRead(GPIO_LIMIT_SWITCH_TOP) << endl;
        cout << "Calibration Switch: " << gpioRead(GPIO_ZERO_SWITCH) << endl;
        cout << "Light Gate:" << gpioRead(GPIO_LIGHTGATE) << endl;
        cout << "\n ITERATION:: " << i << endl;
        i = i+1;
        std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(1)));

    }

*/
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
#include "DataBaseUnitTest.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"

using namespace std;


LimitSwitch* PIR_sensor = new LimitSwitch(26); //physical pin 37
LimitSwitch* upper_switch = new LimitSwitch(22); //
LimitSwitch* lower_switch = new LimitSwitch(27); //
LimitSwitch* calibration_switch = new LimitSwitch(22); //

Motor* carousel_motor = new Motor(8,7,1,25, 2.25);  //GPIO 8, 7,1, 25 Physical pins 24,26,28,22
Motor* riser_motor = new Motor(18,23,24,15,2.7);    //GPIO 18,23,24,15 Physical pins 12,16,18,10

atomic<bool> system_running(true);
atomic<bool> program_running(true);

void initializePins(){
	//PIR Sensor
	gpioSetMode(PIR_sensor->getPin(), PI_INPUT);

	//Limit switches
	gpioSetMode(upper_switch->getPin(), PI_INPUT);
	gpioSetMode(lower_switch->getPin(), PI_INPUT);
	gpioSetMode(calibration_switch->getPin(), PI_INPUT);

	//Light Gate

	//Motors
    carousel_motor->initializePins(carousel_motor->getDirPin(),
                                    carousel_motor->getStepPin(),
                                    carousel_motor->getSleepPin(),
                                    carousel_motor->getFaultPin());

    riser_motor->initializePins(riser_motor->getDirPin(),
                                riser_motor->getStepPin(),
                                riser_motor->getSleepPin(),
                                riser_motor->getFaultPin());

}

void safteyCallback(int gpio, int level, uint32_t tick){
    if(level == PI_HIGH){
        system_running = false;
    }
    else{
        system_running = true;
    }
}
void makeDrinkThread(vector<int>& step_queue){
    while(program_running){
        while(system_running){
            // call set to pos 0
            carousel_motor->MAIN_MOTOR_RESET(calibration_switch);
            for(auto& step:step_queue){
                carousel_motor->motor_go(carousel_motor->decideDirection(step), abs(step));
                riser_motor->VERT_MOVE(upper_switch, lower_switch);                
            }
        }
    }
    

}
int LogicTestExecutable(){
    vector<vector<int>> queues = DataBaseExecutable();
    vector<int> step_queue = carousel_motor->getStepQueue(queues[1]);
	int current_position = 0;

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    // start PIR thread
    //start motor thread
    
    gpioSetAlertFunc(upper_switch->getPin(), safteyCallback);
    thread myThread(makeDrinkThread, ref(step_queue));
    
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
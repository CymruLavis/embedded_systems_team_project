
#include <iostream>
#include <thread>
#include <functional>
#include <pigpio.h>
#include <atomic>

#include "LogicTest.h"
#include "DataBaseUnitTest.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"

using namespace std;


LimitSwitch* PIR_sensor = new LimitSwitch(26); //physical pin 37
LimitSwitch* upper_switch = new LimitSwitch(4); //
LimitSwitch* lower_switch = new LimitSwitch(27); //
LimitSwitch* calibration_switch = new LimitSwitch(22); //

Motor* carousel_motor = new Motor(0, 19,3,2,1.8);
Motor* riser_motor = new Motor(20,18,21,16,1.8);

atomic<bool> PIR_running(true);
atomic<bool> upperLimitSwitchInterrupt(false);
atomic<bool> Lower_LST_running(true);
atomic<bool> Base_motor_running(true);
atomic<bool> Riser_motor_running(true);

void initializePins(){
	//PIR Sensor
	gpioSetMode(PIR_sensor->getPin(), PI_INPUT);

	//Limit switches
	gpioSetMode(upper_switch->getPin(), PI_INPUT);
	gpioSetMode(lower_switch->getPin(), PI_INPUT);
	gpioSetMode(calibration_switch->getPin(), PI_INPUT);

	//Light Gate

	//Motors
	gpioSetMode(carousel_motor->getDirPin(), PI_OUTPUT);



}

void safteyThread(){
}
void motorThread(){
    while(true){
        cout << "motor thread " << endl;
    }
}
void upperLimitSwitchCallback(int gpio, int level, uint32_t tick) {
    if (level == PI_HIGH) {
        upperLimitSwitchInterrupt = true;
    }
}

int LogicTestExecutable(){
    vector<vector<int>> queues = DataBaseExecutable();
    vector<int> step_queue = queues[0];
    vector<int> pos_queue = queues[1];
	int current_position = 0;

    // starts saftey thread (PIR and saftey switch)        
    thread myMotorThread(motorThread);
    myMotorThread.detach();

    while(true){
        cout << "Main Loop " << endl;
    }

    myMotorThread.join();

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
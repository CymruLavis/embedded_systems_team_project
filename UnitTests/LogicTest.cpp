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
// As a way to clean up our GPIO assigment. We declare all our GPIO 


int GPIO_LIMIT_SWITCH_TOP = 22;
int GPIO_LIMIT_SWITCH_BOTTOM =17;

int GPIO_ZERO_SWITCH = 11;
int GPIO_LIGHTGATE = 10; 

LimitSwitch* PIR_sensor = new LimitSwitch(16); //physical pin 37
//LimitSwitch* upper_switch = new LimitSwitch(5); //TOP
//LimitSwitch* lower_switch = new LimitSwitch(0); //BOTTOM
//LimitSwitch* calibration_switch = new LimitSwitch(11); //
                                                    // DIRECTION, STEP, SLEEP, FAULT 
Motor* carousel_motor = new Motor(8,7,1,25, 2.25);  //GPIO 8, 7,1, 25 Physical pins 24,26,28,22

                                                    // DIRECTION STEP SLEEP FAULT
                                                    // OG GPIO 18,23,24,15 Physical pins 12,16,18,10
Motor* riser_motor = new Motor(26,19,13,6,2.7);    //GPIO 18,23,24,15 Physical pins 12,16,18,10

atomic<bool> system_running(true);
atomic<bool> program_running(true);

void initializePins(){
	//PIR Sensor
	//gpioSetMode(PIR_sensor->getPin(), PI_INPUT);

	//Limit switches
	//gpioSetMode(upper_switch->getPin(), PI_INPUT);
	//gpioSetMode(lower_switch->getPin(), PI_INPUT);
	//gpioSetMode(calibration_switch->getPin(), PI_INPUT);

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
            std::cout << "\n MAKING A DRINK! ----------- \n";
            bool clockwise=true;
            carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);
            //riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM);
            for (int i = 0; i < 1; ++i) {
                carousel_motor->motor_go(clockwise, abs(180), GPIO_LIGHTGATE);
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(2000)));   
            }
            clockwise=false;
            for (int i = 0; i < 3; ++i) {
                carousel_motor->motor_go(clockwise, abs(60), GPIO_LIGHTGATE);
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(2000)));   
            }
            carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);
            //for(auto& step:step_queue){
            //    carousel_motor->motor_go(carousel_motor->decideDirection(step), abs(step));
            //    std::cout << "MOTOR go complete\n";
            //    riser_motor->VERT_MOVE(upper_switch, lower_switch);                
            //}
            //std::cout << "LOOP COMPLETE\n";
}

int LogicTestExecutable(){
    vector<vector<int>> queues = DataBaseExecutable();


    vector<int> step_queue = carousel_motor->getStepQueue(queues[1]);

    for(auto& step:step_queue){
        std::cout << step;
        std::cout<<"\n";
    }
    
	int current_position = 0;

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    // start PIR thread
    //start motor thread
    
    gpioSetAlertFunc(PIR_sensor->getPin(), safteyCallback);

    // instantiates a thread, calls makedrink
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
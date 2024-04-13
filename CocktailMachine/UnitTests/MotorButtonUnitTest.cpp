#include <pigpio.h>

#include <iostream>
#include <unistd.h>

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <thread>
#include <atomic>

#include <vector>

#include "MotorButtonUnitTest.h"
#include "../Include/Motor.h"
#include "../Include/LimitSwitch.h"
#include "../Include/Data.h"

using namespace std;
// As a way to clean up our GPIO assigment. We declare all our GPIO 


int GPIO_LIMIT_SWITCH_TOP = 22;
int GPIO_LIMIT_SWITCH_BOTTOM =17;

int GPIO_ZERO_SWITCH = 11;
int GPIO_LIGHTGATE = 10; 

Data* myData = new Data();
Motor* myMotor = new Motor(1,2,3,4, 1.8);

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
    carousel_motor->initializePins(carousel_motor->getDirPin(),
                                    carousel_motor->getStepPin(),
                                    carousel_motor->getSleepPin(),
                                    carousel_motor->getFaultPin());

    riser_motor->initializePins(riser_motor->getDirPin(),
                                riser_motor->getStepPin(),
                                riser_motor->getSleepPin(),
                                riser_motor->getFaultPin());

}


int MotorButtonUnitTest::LogicTestExecutable(string desired_drink){

	vector<int> drink_queue = myData->getRecipe(desired_drink);

	vector<int> step_queue = myMotor->getStepQueue(drink_queue);

    std::cout << "\n MAKING A DRINK! ----------- \n";
    carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);

    for(int i = 0; i < step_queue.size(); i++){
        bool clockwise=true;
        std::cout << "\n STEP SIZE THIS ITERATION: " << step_queue[i] << std::endl;
        carousel_motor->motor_go(clockwise, abs(step_queue[i]), GPIO_LIGHTGATE);
        std::cout << "MOTOR go complete\n";
        riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM);                
    }
    std::cout << "LOOP COMPLETE\n"; 

    gpioTerminate();
    return 0;
}
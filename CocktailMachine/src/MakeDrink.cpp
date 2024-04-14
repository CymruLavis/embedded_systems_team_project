#include "../Include/MakeDrink.h"

#include <pigpio.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <thread>
#include <atomic>
#include <vector>
#include "../Include/Data.h"


using namespace std;

MakeDrink::MakeDrink(){
    this->GPIO_LIMIT_SWITCH_TOP = 19; // physical 35
    this->GPIO_LIMIT_SWITCH_BOTTOM =26; // physical 37

    this->GPIO_ZERO_SWITCH = 23; // 16 
    this->GPIO_LIGHTGATE = 1;  // 28
    this->GPIO_PIR = 22; // 15
//dir, step, sleep, fault, step_angle
    // Motor* carousel_motor = new Motor(21,20,16,12, 2.25);  // Physical pins 40,38,36,32
    // Motor* riser_motor = new Motor(13,6,5,0,2.7);    // Physical pins 33, 31,29,27
}

//atomic<bool> system_running(true);
//atomic<bool> program_running(true);

void MakeDrink::initializePins(){
    carousel_motor->initializePins(carousel_motor->getDirPin(),
                                    carousel_motor->getStepPin(),
                                    carousel_motor->getSleepPin(),
                                    carousel_motor->getFaultPin());

    riser_motor->initializePins(riser_motor->getDirPin(),
                                riser_motor->getStepPin(),
                                riser_motor->getSleepPin(),
                                riser_motor->getFaultPin());
}

void MakeDrink::Make_a_drink_thread(string& DrinkName){
    cout << "\n MAKING A DRINK \n"<<endl;
    Data* myData = new Data();

    vector<int> Drink_Positions = myData->getRecipe(DrinkName);
    vector<int> Drink_steps = carousel_motor->getStepQueue(Drink_Positions);

    carousel_motor->MAIN_MOTOR_RESET(this->GPIO_ZERO_SWITCH, this->GPIO_LIGHTGATE);

    bool clockwise = true;
    for (int i = 0; i < Drink_steps.size(); i++) {
        cout << "MOVING TO POSITION:"<< Drink_Positions[i] << endl;
        cout << "MOVING TO POSITION:"<< Drink_steps[i] << endl;
        
        carousel_motor->motor_go(clockwise, abs(Drink_steps[i]), this->GPIO_LIGHTGATE);
        riser_motor->VERT_MOVE(this->GPIO_LIMIT_SWITCH_TOP, this->GPIO_LIMIT_SWITCH_BOTTOM); 
    }
    
}

int MakeDrink::Make_a_drink(string DrinkName){

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }

    this->initializePins();
    // sets up the PIR safety which kills the below thread
    //gpioSetAlertFunc(PIR_sensor->getPin(), safteyCallback);

    // instantiates a thread, calls makedrink
    thread myThread(&MakeDrink::Make_a_drink_thread, ref(DrinkName));
    myThread.join();
    gpioTerminate();

    return 0;
}


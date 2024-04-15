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
#include <pthread.h>

using namespace std;

int GPIO_LIMIT_SWITCH_TOP = 19; // physical 35
int GPIO_LIMIT_SWITCH_BOTTOM = 26; // physical 37
int GPIO_ZERO_SWITCH = 23; // 16 
int GPIO_LIGHTGATE = 1;  // 28
int GPIO_PIR = 22;
int GPIO_VERT_ENABLE = 15;
int GPIO_CAR_ENABLE = 18;

volatile bool inting = 0;
thread myThread;

LimitSwitch* PIR_sensor = new LimitSwitch(GPIO_PIR);
                                    //Direction, Step, Sleep, Fault, Step_size
Motor* carousel_motor = new Motor(21,20,16,12);  // Physical pins 40,38,36,32
Motor* riser_motor = new Motor(13,6,5,0);    // Physical pins 33, 31,29,27

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

void Make_a_drink_thread(string DrinkName){
    initializePins();
    cout << "\n MAKING A DRINK \n"<<endl;
    Data* myData = new Data();

    vector<int> Drink_Positions = myData->getRecipe(DrinkName);
    vector<int> Drink_steps = carousel_motor->getStepQueue(Drink_Positions);

    carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);

    bool clockwise = true;
    for (int i = 0; i < Drink_steps.size(); i++) {
        cout << "MOVING TO POSITION:"<< Drink_Positions[i] << endl;
        cout << "MOVING TO POSITION:"<< Drink_steps[i] << endl;
        
        carousel_motor->motor_go(clockwise, abs(Drink_steps[i]), GPIO_LIGHTGATE);
        riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM); 
        myData->updateVolume(to_string(Drink_Positions[i]+1));
    }

    gpioWrite(GPIO_VERT_ENABLE, PI_HIGH); //gpio of vertical motor enable
    gpioWrite(GPIO_CAR_ENABLE, PI_HIGH); //gpio of carousel motor enable 
    
}

void displayInterrupt(int gpio, int edge, uint32_t tick)
{
    if(inting == 0){
        cout << "Interrupted" << endl;
        cout << "Motor pin turned off." << endl;
        gpioWrite(15, PI_HIGH); //gpio of vertical motor enable
        gpioWrite(18, PI_HIGH); //gpio of carousel motor enable
        //std::this_thread::sleep_for(std::chrono::seconds(10));

        pthread_cancel(myThread.native_handle());

        time_sleep(1);
    }

}

int Make_a_drink(string DrinkName){

    if (gpioInitialise() < 0) {
        std::cerr << "pigpio initialization failed." << std::endl;
        return 1;
    }
    // low latency safety sensor
    gpioSetMode(GPIO_PIR, PI_INPUT); 
   	gpioSetPullUpDown(GPIO_PIR, PI_PUD_DOWN); 

    // safety sensor interacts with the enable pins of the motor
    // When set high it emergency stops the system.
    gpioSetMode(GPIO_VERT_ENABLE, PI_OUTPUT); 
    gpioSetMode(GPIO_CAR_ENABLE, PI_OUTPUT); 

    gpioWrite(GPIO_VERT_ENABLE, PI_LOW); //gpio of vertical motor enable
    gpioWrite(GPIO_CAR_ENABLE, PI_LOW); //gpio of carousel motor enable 

    // sets up the interrupt in the PIR pin.
   	gpioSetISRFunc(GPIO_PIR, RISING_EDGE, 0, displayInterrupt);

    // instantiates the make a drink thread as an independent thread 
    myThread = thread(Make_a_drink_thread, ref(DrinkName));

    myThread.join();
    gpioTerminate();

    return 0;
}


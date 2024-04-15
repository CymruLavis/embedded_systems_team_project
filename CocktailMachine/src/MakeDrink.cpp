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

volatile bool inting = 0;
thread myThread;

//LimitSwitch* PIR_sensor = new LimitSwitch(GPIO_PIR);

                                    //Direction, Step, Sleep, Fault, Step_size
Motor* carousel_motor = new Motor(21, 20, 16, 12, 18);  // Physical pins 40,38,36,32
Motor* riser_motor = new Motor(13, 6, 5, 0, 15);    // Physical pins 33, 31,29,27

void initializePins(){
    carousel_motor->initializePins(carousel_motor->getDirPin(),
                                    carousel_motor->getStepPin(),
                                    carousel_motor->getSleepPin(),
                                    carousel_motor->getFaultPin(),
                                    carousel_motor->getEnPin());

    riser_motor->initializePins(riser_motor->getDirPin(),
                                riser_motor->getStepPin(),
                                riser_motor->getSleepPin(),
                                riser_motor->getFaultPin(),
                                riser_motor->getEnPin());
}

void Make_a_drink_thread(string DrinkName){

    initializePins();
    carousel_motor->Enable_Motors();
    riser_motor->Enable_Motors();

    //charging capacitors
    this_thread::sleep_for(chrono::seconds(static_cast<int>(0.25)));

    cout << "\n MAKING A DRINK \n"<<endl;
    Data* myData = new Data();

    vector<int> Drink_Positions = myData->getRecipe(DrinkName);
    vector<int> Drink_steps = carousel_motor->getStepQueue(Drink_Positions);

    carousel_motor->MAIN_MOTOR_RESET(GPIO_ZERO_SWITCH, GPIO_LIGHTGATE);
    //sets direction.
    bool clockwise = true;
    for (int i = 0; i < Drink_steps.size(); i++) {
        cout << "MOVING TO POSITION:"<< Drink_Positions[i] << endl;
        cout << "MOVING TO POSITION:"<< Drink_steps[i] << endl;
        if (Drink_steps[i] < 0){
            clockwise = false;
        }
        carousel_motor->motor_go(clockwise, abs(Drink_steps[i]), GPIO_LIGHTGATE);
        riser_motor->VERT_MOVE(GPIO_LIMIT_SWITCH_TOP, GPIO_LIMIT_SWITCH_BOTTOM); 
        myData->updateVolume(to_string(Drink_Positions[i]+1));
    }

    carousel_motor-> Disable_Motors();
    riser_motor->Disable_Motors();
    
}

void INTERRUPT(int gpio, int edge, uint32_t tick)
{
    if(inting == 0){
        cout << "INTERRUPT TRIGGERED, PIR" << endl;
        cout << "Disabling motors." << endl;

        carousel_motor-> Disable_Motors();
        riser_motor->Disable_Motors();

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


    // sets up the interrupt in the PIR pin.
   	gpioSetISRFunc(GPIO_PIR, RISING_EDGE, 0, INTERRUPT);
    //gpioSetISRFunc(carousel_motor->getFaultPin(), FALLING_EDGE, 0, INTERRUPT);
    //gpioSetISRFunc(riser_motor->getFaultPin(), FALLING_EDGE, 0, INTERRUPT);

    // instantiates the make a drink thread as an independent thread 
    myThread = thread(Make_a_drink_thread, ref(DrinkName));

    myThread.join();
    gpioTerminate();

    return 0;
}


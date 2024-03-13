#include<iostream>
#include "SWITCH_CONTROL_H.h"
#include <iostream>
#include  <pigpio.h>
#include  <thread>

void switchMonitor (int switchIndex, SwitchControl& switchControl){
     while (true) {
        if (switchControl.isSwitchOn(switchIndex)){
            std::cout<<"Switch "<<switchIndex+1<<"IS ON/n";
        }else {
            std::cout<<"Switch "<<switchIndex+1<<"IS OFF/n";
        }
     }
 }
    
    


int main() {
    
     std::vector<int>SwitchPins = {7,13,15};
     SwitchControl switchControl (SwitchPins);

     if(!switchControl.intialize()){
        std::cout<<"initialization failed.\n";
        return 1;
     }
     std::vector<std::thread> threads;
     for (int i= 0; i < SwitchPins.size();i++){
         threads.emplace_back(switchMonitor , i, std::ref(switchControl));
     }
     //waiting for the threads to finish of which it never does
     for(std::thread& t:threads) {
         t.join();
     }
     
     

    return 0;

}



#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <typeinfo>
#include <QApplication>
#include <pigpio.h>
#include <vector>
#include <QSplashScreen>
#include <QTimer>
#include <stdio.h>

#include "Include/Data.h"
// #include "Include/SystemConfig.h"
#include "Include/Motor.h"
#include "Include/LimitSwitch.h"
#include "Include/Interrupt.h"

#define PIN 21
// #include "UnitTests/LimitSwitchUnitTest.h"
// #include "UnitTests/PIRUnitTest.h"
//#include "UnitTests/DataBaseUnitTest.h"

using namespace std;

// LimitSwitch* PIR_sensor = new LimitSwitch(26); //physical pin 37
// LimitSwitch* upper_switch = new LimitSwitch(4); //
// LimitSwitch* lower_switch = new LimitSwitch(27); //
// LimitSwitch* calibration_switch = new LimitSwitch(22); //

// Motor* carousel_motor = new Motor(0, 19,3,2,1.8);
// Motor* riser_motor = new Motor(20,18,21,16,1.8);

// Data* myData = new Data();


// void initializePins(){
// 	//PIR Sensor
// 	gpioSetMode(PIR_sensor->getPin(), PI_INPUT);

// 	//Limit switches
// 	gpioSetMode(upper_switch->getPin(), PI_INPUT);
// 	gpioSetMode(lower_switch->getPin(), PI_INPUT);
// 	gpioSetMode(calibration_switch->getPin(), PI_INPUT);

// 	//Light Gate

// 	//Motors
// 	gpioSetMode(carousel_motor->getDirPin(), PI_OUTPUT);



// }

int main()
{
    //int argc, char *argv[]
	// QApplication a(argc, argv);
	// QPixmap pixmap("../splash.png");
	// pixmap = pixmap.scaled(480, 320, Qt::KeepAspectRatio);
	// QSplashScreen *splash = new QSplashScreen;
	// splash->setPixmap(pixmap);
	// splash->show();

    // MainWindow w;
	// w.setWindowState(Qt::WindowFullScreen);

	// QTimer::singleShot(2500, splash, SLOT(close()));
	// QTimer::singleShot(2500, &w, SLOT(show()));

    // return a.exec();

	Interrupt* inter = new Interrupt();

	gpioInitialise();
   	gpioSetMode(PIN, PI_INPUT); 
   	gpioSetPullUpDown(PIN, PI_PUD_DOWN); 
   	gpioSetISRFunc(PIN, RISING_EDGE, 0, inter->displayInterrupt);
	int i = 0;
   	while(1){
		time_sleep(1);
		cout << "\n hell0     " << i;
		i = i+1;
		cout << "\t"<< gpioRead(PIN) << endl;
   	} 

	return 0;

}

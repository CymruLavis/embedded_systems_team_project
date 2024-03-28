#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <QApplication>

#include "Include/Data.h"
#include "Include/SystemConfig.h"
#include "Include/Motor.h"
#include "Include/LimitSwitch.h"

// #include "UnitTests/LimitSwitchUnitTest.h"
// #include "UnitTests/PIRUnitTest.h"
// #include "UnitTests/DataBaseUnitTest.h"

using namespace std;

LimitSwitch* PIR_sensor = new LimitSwitch(26); //physical pin 37
LimitSwitch* upper_switch = new LimitSwitch(4); //
LimitSwitch* lower_switch = new LimitSwitch(27); //
LimitSwitch* calibration_switch = new LimitSwitch(22); //

Motor* carousel_motor = new Motor(0, 19,3,2,1.8);
Motor* riser_motor = new Motor(20,18,21,16,1.8);



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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

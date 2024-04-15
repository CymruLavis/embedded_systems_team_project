#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <typeinfo>
#include <QApplication>
#include <pigpio.h>
#include <vector>
#include <QSplashScreen>
#include <QTimer>

#include "Include/Data.h"
#include "Include/Motor.h"
#include "Include/LimitSwitch.h"

using namespace std;


int main(int argc, char *argv[])
{
    
	QApplication a(argc, argv);
	QPixmap pixmap("../splash.png");
	pixmap = pixmap.scaled(480, 320, Qt::KeepAspectRatio);
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(pixmap);
	splash->show();

    MainWindow w;
	w.setWindowState(Qt::WindowFullScreen);

	QTimer::singleShot(2500, splash, SLOT(close()));
	QTimer::singleShot(2500, &w, SLOT(show()));

    return a.exec();
}
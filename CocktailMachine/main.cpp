#include "mainwindow.h"
#include <iostream>
#include <thread>
#include <typeinfo>
#include <QApplication>
#include <pigpio.h>
#include <vector>
#include <QSplashScreen>
#include <QTimer>

using namespace std;


int main(int argc, char *argv[])
{
    //Creating a Qt application
	QApplication a(argc, argv);

	//Splash screen
	QPixmap pixmap("../splash.png");
	pixmap = pixmap.scaled(480, 320, Qt::KeepAspectRatio);
	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(pixmap);
	splash->show();

	//Main Window Instantiation
    MainWindow w;
	w.setWindowState(Qt::WindowFullScreen);

	QTimer::singleShot(2500, splash, SLOT(close()));
	QTimer::singleShot(2500, &w, SLOT(show()));

	//App launch
    return a.exec();
}
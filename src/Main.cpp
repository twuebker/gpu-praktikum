#include <iostream>
#include <vector>
#include <QWindow>
#include <QApplication>
#include <QMainWindow>
#include "AsteroidsScene.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QMainWindow mainWindow;
	mainWindow.setWindowTitle("Hello World");
	mainWindow.resize(320, 200);
	auto asteroids = std::vector<Asteroid*>();
	AsteroidsScene scene = AsteroidsScene(&mainWindow, asteroids);
	mainWindow.show();
	return QApplication::exec();
}




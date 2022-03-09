#include <iostream>
#include <vector>
#include <QWindow>
#include <QApplication>
#include "GuiMainWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	GuiMainWindow mw;
	mw.show();
	return QApplication::exec();
}




#include <iostream>
#include <vector>
#include <QWindow>
#include <QApplication>
#include "GuiMainWindow.h"
#include "../cuda/physics.cu" 

int main(int argc, char** argv)
{
	float res = call_kernel(2.0, 3.0);
	std::cout << res << std::endl;
	QApplication app(argc, argv);
	GuiMainWindow mw;
	mw.show();
	return QApplication::exec();
}




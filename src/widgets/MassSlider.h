#ifndef MASS_SLIDER_H
#define MASS_SLIDER_H

#include "AsteroidsScene.h"
#include <QtWidgets>

class MassSlider : public QSlider {

public:
	MassSlider(Ui::MainWindow* mainWindow, int index);
public slots:
	void changeMass();
	void changeUi(int mass);
private:
	Ui::MainWindow* m_mainWindow;
	int m_index;
};

#endif

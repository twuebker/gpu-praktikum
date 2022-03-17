#ifndef MASS_SLIDER_H
#define MASS_SLIDER_H

#include "AsteroidsScene.h"
#include <QtWidgets>
#include "AsteroidPixmapItem.h"

class MassSlider : public QSlider {

public:
	MassSlider(AsteroidPixmapItem* item, Ui::MainWindow* mainWindow, int index);
public slots:
	void changeMass();
	void changeUi(int mass);
private:
	AsteroidPixmapItem* m_associatedItem;
	Ui::MainWindow* m_mainWindow;
	int m_index;
};

#endif

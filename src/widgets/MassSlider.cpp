#include "MassSlider.h"
#include <iostream>

MassSlider::MassSlider(Ui::MainWindow* mainWindow, int index) : m_mainWindow(mainWindow), m_index(index) {
	connect(this, &QSlider::sliderReleased, this, &MassSlider::changeMass);
	setOrientation(Qt::Horizontal);
	setMinimum(1);
	setMaximum(1000);
	setTickInterval(10);
	setSingleStep(10);
}

void MassSlider::changeMass() {
	int newMass = value();
	AsteroidsScene* scene = dynamic_cast<AsteroidsScene*>(m_mainWindow->asteroidsView->scene());
	scene->updateMass(m_index, newMass);
}




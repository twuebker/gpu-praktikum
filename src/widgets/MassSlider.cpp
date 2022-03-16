#include "MassSlider.h"
#include <iostream>

MassSlider::MassSlider(Ui::MainWindow* mainWindow, int index) : m_mainWindow(mainWindow), m_index(index) {
	std::cout << "Connected" << std::endl;
	setOrientation(Qt::Horizontal);
	//setMinimum(1);
	//setMaximum(1000);
	//setTickInterval(10);
	//setSingleStep(10);
	std::cout << "Constructor ready"<< std::endl;
	connect(this, &QSlider::sliderReleased, this, &MassSlider::changeMass);
        connect(this, &QSlider::valueChanged, this, &MassSlider::changeUi);
}

void MassSlider::changeMass() {
	int newMass = value();
	AsteroidsScene* scene = dynamic_cast<AsteroidsScene*>(m_mainWindow->asteroidsView->scene());
	scene->updateMass(m_index, newMass);
}

void MassSlider::changeUi(int mass){
        AsteroidsScene* scene = dynamic_cast<AsteroidsScene*>(m_mainWindow->asteroidsView->scene());
        scene->updateAsteroidUi(m_index, mass);
}


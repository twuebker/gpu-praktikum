#include "MassSlider.h"
#include <iostream>

MassSlider::MassSlider(AsteroidPixmapItem* item, Ui::MainWindow* mainWindow, int index) : m_mainWindow(mainWindow), m_index(index) {
	m_associatedItem = item;
	setOrientation(Qt::Horizontal);
	setMinimum(1);
	setMaximum(1000);
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
        scene->updateAsteroidUi(m_associatedItem, m_index, mass);
}


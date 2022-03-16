#include "GuiMainWindow.h"
#include "../cuda/physics_v2.cu"

GuiMainWindow::GuiMainWindow() {
	d_asteroid = nullptr;
	d_forceField = nullptr;
	setupUi(this);
	m_animate = false;
	this->pushButton->setText("Reset");
 	m_asteroids = std::vector<Asteroid>();
	m_forceFields = std::vector<ForceField>();
	m_scene = new AsteroidsScene(m_asteroids, m_forceFields, this);	
	this->asteroidsView->setScene(m_scene);
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &GuiMainWindow::calcPhysics);
	connect(this->toggleSimulation, &QCheckBox::stateChanged, this, &GuiMainWindow::toggle);
	connect(this->pushButton, &QPushButton::pressed, this, &GuiMainWindow::reset);
	connect(this->toggleFastplace, &QCheckBox::stateChanged, this, &GuiMainWindow::toggleFastPlacing);
	connect(this->placeAsteroids, &QPushButton::pressed, this, &GuiMainWindow::updatePlaceAsteroids);
	connect(this->animationSpeedSlider, &QSlider::sliderReleased, this, &GuiMainWindow::updateAnimationSpeed);
	m_timer->start(1000);
	this->placeAsteroids->setText("Place Asteroids");
	scrollAreaWidgetContents->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	scrollAreaWidgetContents->setLayout(new QVBoxLayout(scrollAreaWidgetContents));

	//QColor color = QColor(0,0,0,255);
	//QBrush brush = QBrush(color);
	QImage img = QImage(":/resources/background.jpg");
	QPixmap pix = QPixmap::fromImage(img);
	this->asteroidsView->setBackgroundBrush(pix);
}

void GuiMainWindow::calcPhysics() {
	if(m_animate) {
		if(m_scene->isChanged() || m_changed) {
			std::cout << "We changed" << std::endl;
			freeDeviceMemory(d_asteroid, d_forceField);
			std::pair<Asteroid*, ForceField*> resultPair = updateMemory(m_asteroids, m_forceFields);
			d_asteroid = resultPair.first;
			d_forceField = resultPair.second;
			m_changed = false;
			m_scene->setChanged(false);
		}
		call_kernel_v2(m_asteroids.data(), d_asteroid, d_forceField, m_asteroids.size(), m_forceFields.size());
		m_scene->update();
	}
}

void GuiMainWindow::toggle(int state) {
	m_animate = state;
}

void GuiMainWindow::toggleFastPlacing(int state) {
	m_scene->updateFastplace(state);
}

void GuiMainWindow::updatePlaceAsteroids() {
	m_scene->updatePlaceAsteroids();
}

void GuiMainWindow::updateAnimationSpeed() {
	m_timer->setInterval(this->animationSpeedSlider->value());
}
void GuiMainWindow::reset() {
	m_changed = true;
	m_asteroids.clear();
	QLayoutItem* item;
	while( (item = scrollAreaWidgetContents->layout()->takeAt(0)) != nullptr) {
		scrollAreaWidgetContents->layout()->removeItem(item);
		delete item->widget();
		delete item;
	}
	for(QGraphicsItem* qitem : m_scene->items()) {
	      	m_scene->removeItem(qitem);
       		delete qitem;
	}	       
}

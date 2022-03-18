#include "GuiMainWindow.h"
#include "../cuda/physics_v3.cu"
#include <cuda.h>
#include <cuda_runtime.h>

float2* d_accs;

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
	m_timer->start(100);
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
			freeDeviceMemory_v3(d_asteroid, d_forceField, d_accs);
			std::tuple<Asteroid*, ForceField*, float2*> resultTuple = updateMemory_v3(m_asteroids, m_forceFields);
			d_asteroid = std::get<0>(resultTuple);
			d_forceField = std::get<1>(resultTuple);
			d_accs = std::get<2>(resultTuple);
			m_changed = false;
			m_scene->setChanged(false);
		}
		call_kernel_v3(m_asteroids.data(), d_asteroid, d_forceField, m_asteroids.size(), m_forceFields.size(), d_accs);
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
std::cout << this->animationSpeedSlider->value() << std::endl;	
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

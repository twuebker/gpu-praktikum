#include "GuiMainWindow.h"
#include "../cuda/physics.cu"

GuiMainWindow::GuiMainWindow() {
	setupUi(this);
	m_animate = false;
	this->pushButton->setText("Reset");
 	m_asteroids = std::vector<Asteroid>();
	m_forceFields = std::vector<ForceField>();
	m_scene = new AsteroidsScene(m_asteroids, m_forceFields, this);	
	this->asteroidsView->setScene(m_scene);
	auto* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GuiMainWindow::calcPhysics);
	connect(this->toggleSimulation, &QCheckBox::stateChanged, this, &GuiMainWindow::toggle);
	connect(this->pushButton, &QPushButton::pressed, this, &GuiMainWindow::reset);
	connect(this->toggleFastplace, &QCheckBox::stateChanged, this, &GuiMainWindow::toggleFastPlacing);
	connect(this->placeAsteroids, &QPushButton::pressed, this, &GuiMainWindow::updatePlaceAsteroids);
	timer->start(100);
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
		call_kernel(m_asteroids);
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
void GuiMainWindow::reset() {
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

#include "GuiMainWindow.h"
#include "../cuda/physics.cu"

GuiMainWindow::GuiMainWindow() {
	setupUi(this);
	m_animate = false;
	this->pushButton->setText("Reset");
 	m_asteroids = std::vector<Asteroid>();
	m_scene = new AsteroidsScene(m_asteroids, this);	
	this->asteroidsView->setScene(m_scene);
	auto* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GuiMainWindow::calcPhysics);
	connect(this->toggleSimulation, &QCheckBox::stateChanged, this, &GuiMainWindow::toggle);
	connect(this->pushButton, &QPushButton::pressed, this, &GuiMainWindow::reset);
	timer->start(100);
	scrollAreaWidgetContents->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	scrollAreaWidgetContents->setLayout(new QVBoxLayout(scrollAreaWidgetContents));

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

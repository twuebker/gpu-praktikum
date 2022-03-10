#include "GuiMainWindow.h"
#include "../cuda/physics.cu"

GuiMainWindow::GuiMainWindow() {
	setupUi(this);
 	m_asteroids = std::vector<Asteroid>();
	m_scene = new AsteroidsScene(m_asteroids, this);	
	this->asteroidsView->setScene(m_scene);
	auto* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GuiMainWindow::calcPhysics);
	timer->start(100);
}

void GuiMainWindow::calcPhysics() {
	call_kernel(m_asteroids);
	m_scene->update();
	
}

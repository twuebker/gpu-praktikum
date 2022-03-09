#include "GuiMainWindow.h"

GuiMainWindow::GuiMainWindow() {
	setupUi(this);
 	m_asteroids = std::vector<Asteroid*>();	
	this->asteroidsView->setScene(new AsteroidsScene(m_asteroids));
	auto* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GuiMainWindow::calcPhysics);
	timer->start(10000);
}

void GuiMainWindow::calcPhysics() {
	std::cout << "KING SHIT" << std::endl;	
}

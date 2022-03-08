#include "GuiMainWindow.h"

GuiMainWindow::GuiMainWindow() {
	setupUi(this);
 	m_asteroids = std::vector<Asteroid*>();	
	this->asteroidsView->setScene(new AsteroidsScene(m_asteroids));
}

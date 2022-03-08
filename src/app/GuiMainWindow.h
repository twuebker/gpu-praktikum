#include "ui_MainWindow.h"
#include <QtWidgets>
#include "AsteroidsScene"

class GuiMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	GuiMainWindow();
	~GuiMainWinow();
private:
	std::vector<Asteroid*> m_asteroids;
}


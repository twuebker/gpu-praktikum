#include "../ui/ui_MainWindow.h"
#include <QtWidgets>
#include "../widgets/AsteroidsScene.h"
#include <iostream>
#include <QTimer>

class GuiMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	GuiMainWindow();
public slots:
	void calcPhysics();
private:
	std::vector<Asteroid*> m_asteroids;
};


#include "../ui/ui_MainWindow.h"
#include <QtWidgets>
#include "../widgets/AsteroidsScene.h"

class GuiMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	GuiMainWindow();

private:
	std::vector<Asteroid*> m_asteroids;
};


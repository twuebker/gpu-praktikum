#include "AsteroidsScene.h"
#include <QtWidgets>

class MassSlider : public QSlider {

public:
	MassSlider(Ui::MainWindow* mainWindow, int index);
public slots:
	void changeMass();
private:
	Ui::MainWindow* m_mainWindow;
	int m_index;
};

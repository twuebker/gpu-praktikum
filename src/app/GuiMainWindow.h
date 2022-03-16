#ifndef GUI_MAIN_WINDOW_H
#define GUI_MAIN_WINDOW_H

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
	void toggle(int state);
	void toggleFastPlacing(int state);
	void updatePlaceAsteroids();
	void updateAnimationSpeed();
	void reset();
private:
	std::vector<Asteroid> m_asteroids;
	std::vector<ForceField> m_forceFields;
	Asteroid* d_asteroid;
	ForceField* d_forceField;
	bool m_changed;
	AsteroidsScene* m_scene;
	bool m_animate;
};


#endif

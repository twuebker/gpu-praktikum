#ifndef SRC_WIDGETS_ASTEROIDS_SCENE_H
#define SRC_WIDGETS_ASTEROIDS_SCENE_H

#include <utility> 
#include <vector>
#include <QtGui>
#include <QGraphicsScene>
#include "../app/CreateForceFieldDialog.h"
#include "../ui/ui_MainWindow.h"
#include "ForceFieldPixmapItem.h"
#include "../data/data.h"

class AsteroidsScene : public QGraphicsScene {
	Q_OBJECT
public:
	AsteroidsScene(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields, Ui::MainWindow* mainWindow);
	void update();	
	void updateMass(int index, int newMass);
	void updateAsteroidUi(int index, int newMass);
	void addForceField(QGraphicsSceneMouseEvent* event);
	void addAsteroid(QGraphicsSceneMouseEvent* event);
	void updateFastplace(int state);
	void updatePlaceAsteroids();
	void setChanged(bool changed);
	bool isChanged();
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
	std::vector<Asteroid>& m_asteroids;
	std::vector<ForceField>& m_forceFields;
	std::vector<QPixmap> m_animationLevels;	
	QPixmap m_pixmap;
	Ui::MainWindow* m_mainWindow;
	bool m_fastPlaceEnabled;
	bool m_placeAsteroids;
	bool m_changed;
	void fillAnimationLevels();
};
#endif

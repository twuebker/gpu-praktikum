#ifndef SRC_WIDGETS_ASTEROIDS_SCENE_H
#define SRC_WIDGETS_ASTEROIDS_SCENE_H

#include <utility> 
#include <vector>
#include <QtGui>
#include <QGraphicsScene>
#include "../ui/ui_MainWindow.h"

struct ast{
        std::pair<float, float> pos;
        std::pair<float, float> velocity;
        float mass;
        } typedef Asteroid;

class AsteroidsScene : public QGraphicsScene {
	Q_OBJECT
public:
	AsteroidsScene(std::vector<Asteroid>& asteroids, Ui::MainWindow* mainWindow);
	void update();	
	void updateMass(int index, int newMass);
	void addAsteroid(QGraphicsSceneMouseEvent* event);
	void updateFastplace(int state);

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
	std::vector<Asteroid>& m_asteroids;	
	QPixmap m_pixmap;
	Ui::MainWindow* m_mainWindow;
	bool m_fastPlaceEnabled;
};
#endif

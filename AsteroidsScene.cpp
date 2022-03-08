#include "AsteroidsScene.h"

AsteroidsScene::AsteroidsScene(QMainWindow* mainWindow, std::vector<Asteroid*> asteroids) : QGrapicsScene(0,0,mainWindow->width(), mainWindow->height(), mainWindow) {
	m_asteroids = asteroids;
}

AsteroidsScene::mousePressEvent(QGrapicsSceneMouseEvent* event) {
	Asteroid* = new Asteroid();
	QPointF clickPos = event.scenePos();
	
	asteroid->pos.first = clickPos.x();
       	asteroid->pos.second = clickPos.y();
	asteroid->velocity.first = 0.0;
	asteroid->velocity.second = 0.0;
	asteroid->acceleration.first = 0.0;
	asteroid->acceleration.second = 0.0;
	m_asteroids.push_back(asteroid);	
}

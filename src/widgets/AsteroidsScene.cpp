#include "AsteroidsScene.h"
#include <QGraphicsSceneEvent>
#include <iostream>
AsteroidsScene::AsteroidsScene(std::vector<Asteroid*>& asteroids)
	: m_asteroids(asteroids) {
}
void AsteroidsScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	std::cout << "MOIN" << std::endl;
	Asteroid* asteroid = new Asteroid();
	QPointF clickPos = event->scenePos();
	
	asteroid->pos.first = clickPos.x();
       	asteroid->pos.second = clickPos.y();
	asteroid->velocity.first = 0.0;
	asteroid->velocity.second = 0.0;
	asteroid->acceleration.first = 0.0;
	asteroid->acceleration.second = 0.0;
	m_asteroids.push_back(asteroid);	
}

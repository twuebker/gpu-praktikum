#include "AsteroidsScene.h"
#include <QGraphicsSceneEvent>
#include <iostream>
#include <QtWidgets>
#include "AsteroidPixmapItem.h"

AsteroidsScene::AsteroidsScene(std::vector<Asteroid>& asteroids, Ui::MainWindow* mainWindow)
	: m_asteroids(asteroids), m_mainWindow(mainWindow) {
	QImage image(":/resources/ast.png");
        m_pixmap = QPixmap::fromImage(image).scaled(10, 10, Qt::KeepAspectRatio
);
	AsteroidPixmapItem* initialItem = new AsteroidPixmapItem(-1, m_pixmap);
	addItem(initialItem);
	initialItem->hide();

}
void AsteroidsScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	Asteroid asteroid{};
	QPointF clickPos = event->scenePos();
	
	asteroid.pos.first = clickPos.x();
       	asteroid.pos.second = clickPos.y();
	std::cout << "initial: " << asteroid.pos.first << "," << asteroid.pos.second << std::endl;
	asteroid.velocity.first = 0.0;
	asteroid.velocity.second = 0.0;
	asteroid.mass = 10.0;
	m_asteroids.push_back(asteroid);

	AsteroidPixmapItem *item = new AsteroidPixmapItem(m_asteroids.size() - 1, m_pixmap);
	item->setPos(clickPos);
	addItem(item);

	QSlider* slider = new QSlider(Qt::Horizontal);
	slider->setMaximumWidth(m_mainWindow->sliderLayout->itemAt(0)->sizeHint().width());
	m_mainWindow->sliderTable->setCellWidget(m_mainWindow->sliderTable->rowCount(),0, slider);
}

void AsteroidsScene::update() {
	for(QGraphicsItem* item : this->items()) {
		auto* ast = dynamic_cast<AsteroidPixmapItem*>(item);
		if(ast->getIndex() == -1) {
			continue;
		}
		ast->update(m_asteroids[ast->getIndex()]);
	}
}

#include "AsteroidsScene.h"
#include <QGraphicsSceneEvent>
#include <iostream>
#include <QtWidgets>
#include <string>
#include "AsteroidPixmapItem.h"
#include "MassSlider.h"


AsteroidsScene::AsteroidsScene(std::vector<Asteroid>& asteroids, std::vector<ForceField>& forceFields, Ui::MainWindow* mainWindow)
	: m_asteroids(asteroids), m_mainWindow(mainWindow), m_forceFields(forceFields) {
	QImage image(":/resources/ast.png");
        m_pixmap = QPixmap::fromImage(image).scaled(20, 20, Qt::KeepAspectRatio
);
	AsteroidPixmapItem* initialItem = new AsteroidPixmapItem(-1, m_pixmap);
	addItem(initialItem);
	initialItem->hide();
	m_fastPlaceEnabled = false;
	m_placeAsteroids = true;

	m_animationLevels = std::vector<QPixmap>();
	fillAnimationLevels();
}
void AsteroidsScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	if(m_placeAsteroids) {
		addAsteroid(event);
	} else {
		addForceField(event);
	}
	
}

void AsteroidsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
	if(m_fastPlaceEnabled) {
		if(m_placeAsteroids) {
			addAsteroid(event);
		} else {
			addForceField(event);
		}
	}
}

void AsteroidsScene::addAsteroid(QGraphicsSceneMouseEvent* event) {
	Asteroid asteroid{};
        QPointF clickPos = event->scenePos();

        asteroid.pos.first = clickPos.x();
        asteroid.pos.second = clickPos.y();
        asteroid.velocity.first = 0.0;
        asteroid.velocity.second = 0.0;
        asteroid.mass = 10.0;
        m_asteroids.push_back(asteroid);

        AsteroidPixmapItem *item = new AsteroidPixmapItem(m_asteroids.size() - 1, m_pixmap);
        item->setPos(clickPos);
        addItem(item);

        MassSlider* slider = new MassSlider(m_mainWindow, m_asteroids.size() - 1);
        m_mainWindow->scrollAreaWidgetContents->layout()->addWidget(slider);
}

void AsteroidsScene::addForceField(QGraphicsSceneMouseEvent* event) {
	ForceField field{};
	QPointF clickPos = event->scenePos();
	CreateForceFieldDialog dialog{};
	dialog.exec();
	if(dialog.result() == 0) {
		return;
	}
	field.leftCorner.first = clickPos.x();
	field.leftCorner.second = clickPos.y();
	field.rightCorner.first = clickPos.x() + dialog.getWidth();
	field.rightCorner.second = clickPos.y() + dialog.getHeight();
	field.force = dialog.getForce();
	m_forceFields.push_back(field);

	ForceFieldPixmapItem* item = new ForceFieldPixmapItem(m_animationLevels);
	item->setPos(clickPos);
	addItem(item);
}

void AsteroidsScene::updateMass(int index, int newMass) {
	m_asteroids[index].mass = newMass;
	std::cout << m_asteroids[index].mass << std::endl;
}

void AsteroidsScene::updateFastplace(int state) {
	m_fastPlaceEnabled = state;
}

void AsteroidsScene::updatePlaceAsteroids() {
	m_placeAsteroids = !m_placeAsteroids;
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

void AsteroidsScene::fillAnimationLevels() {
	for(int i = 1; i < 17; i++) {
		std::string name = ":/resources/W401-" + std::to_string(i) + ".png";
		QImage image = QImage(QString::fromStdString(name));
		QPixmap pm = QPixmap::fromImage(image).scaled(20,20,Qt::KeepAspectRatio);
		m_animationLevels.push_back(pm);
	}
}

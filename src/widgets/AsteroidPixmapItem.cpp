#include "AsteroidPixmapItem.h"
#include <iostream>

AsteroidPixmapItem::AsteroidPixmapItem(int index, QPixmap pixmap) : m_index(index) {
	setPixmap(pixmap);
	
}

void AsteroidPixmapItem::update(Asteroid a) {

	setPos(QPointF(a.pos.first, a.pos.second));
}

#include "AsteroidPixmapItem.h"
#include <iostream>

AsteroidPixmapItem::AsteroidPixmapItem(int index, QPixmap pixmap) : m_index(index) {
	setPixmap(pixmap);
	setOffset(-1 * pixmap.width() / 2, -1 * pixmap.height() /2);
	
}


void AsteroidPixmapItem::update(Asteroid a) {

	setPos(QPointF(a.pos.first, a.pos.second));
}

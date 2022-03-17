#ifndef AsteroidPixmapItem_h
#define AsteroidPixmapItem_h

#include <QtWidgets>
#include "../data/data.h"
#include <utility>

class AsteroidPixmapItem : public QGraphicsPixmapItem {

public:
	AsteroidPixmapItem(int index, QPixmap pixmap);
	void update(Asteroid a);
	int getIndex() {
		return m_index;
	};
private:			
	int m_index;
};
#endif

#include <QtWidgets>
#include "AsteroidsScene.h"
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

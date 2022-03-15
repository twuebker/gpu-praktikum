#ifndef ForceFieldPixmapItem_h
#define ForceFieldPixmapItem_h

#include <QtWidgets>
#include <vector>
#include <QtGui>
#include <utility>
#include "../data/data.h"

class ForceFieldPixmapItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	Q_PROPERTY(int m_animationLevel READ animationLevel WRITE setAnimationLevel)

public: 
	ForceFieldPixmapItem(const std::vector<QPixmap>& animationLevels, int width, int height, Direction dir);
public slots:
	void changePixmap(QVariant variant);	
private:
	int m_animationLevel;
	std::vector<QPixmap> m_animationLevels;
	int animationLevel();
	void setAnimationLevel(int level);
};
#endif



#ifndef ForceFieldPixmapItem_h
#define ForceFieldPixmapItem_h

#include <QtWidgets>
#include <vector>
#include <QtGui>
#include <utility>

class ForceFieldPixmapItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	Q_PROPERTY(int m_animationLevel READ animationLevel WRITE setAnimationLevel)

public: 
	ForceFieldPixmapItem(const std::vector<QPixmap>& animationLevels);
public slots:
	void changePixmap(QVariant variant);	
private:
	int m_animationLevel;
	const std::vector<QPixmap>& m_animationLevels;
	int animationLevel();
	void setAnimationLevel(int level);
};
#endif



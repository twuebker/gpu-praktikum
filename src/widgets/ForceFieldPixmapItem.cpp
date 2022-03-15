#include "ForceFieldPixmapItem.h"
#include <iostream>

ForceFieldPixmapItem::ForceFieldPixmapItem(const std::vector<QPixmap>& animationLevels, int width, int height) {
	m_animationLevel = 0;
	m_animationLevels = std::vector<QPixmap>();
	QPropertyAnimation* anim = new QPropertyAnimation(this, "m_animationLevel");
	anim->setDuration(1000);
	anim->setLoopCount(-1);
	anim->setEndValue(15);
	for(QPixmap pm : animationLevels) {
		m_animationLevels.push_back(pm.scaled(width, height, Qt::KeepAspectRatio));
	}
	
	for(int i = 0; i < 16; i++) {
		anim->setKeyValueAt(i / 16.0, i);
	}
	anim->start();
	connect(anim, &QPropertyAnimation::valueChanged, this, &ForceFieldPixmapItem::changePixmap);
}

void ForceFieldPixmapItem::changePixmap(QVariant variant) {
	this->setPixmap(m_animationLevels[variant.toInt()]);
}

int ForceFieldPixmapItem::animationLevel() {
	return m_animationLevel;
}

void ForceFieldPixmapItem::setAnimationLevel(int level) {
	m_animationLevel = level;
}

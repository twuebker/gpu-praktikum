#include "ForceFieldPixmapItem.h"

ForceFieldPixmapItem::ForceFieldPixmapItem(const std::vector<QPixmap>& animationLevels) : m_animationLevels(animationLevels) {
	m_animationLevel = 0;
	QPropertyAnimation anim(this, "m_animationLevel");
	anim.setDuration(10000);
	for(int i = 0; i < 16; i++) {
		anim.setKeyValueAt(i / 16.0, i);
	}
	anim.start();
	connect(&anim, &QPropertyAnimation::valueChanged, this, &ForceFieldPixmapItem::changePixmap);
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

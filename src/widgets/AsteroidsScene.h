#include <utility> 
#include <vector>
#include <QtGui>
#include <QGraphicsScene>

struct ast{
        std::pair<float, float> pos;
        std::pair<float, float> velocity;
        std::pair<float, float> acceleration;
        float mass;
        } typedef Asteroid;

class AsteroidsScene : public QGraphicsScene {
	Q_OBJECT
public:
	AsteroidsScene(std::vector<Asteroid*>& asteroids) {
        m_asteroids = asteroids;
}
	
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
	std::vector<Asteroid*>& m_asteroids;	
};

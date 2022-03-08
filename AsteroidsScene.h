#include <QGraphicsScene>
#include <utility> 
#include <vector>
#include <QMainWindow>

class AsteroidsScene : public QGraphicsScene {
public:
	struct ast{
        std::pair<float, float> pos;
	std::pair<float, float> velocity;
	std::pair<float, float> acceleration;
        float mass;
	} typedef Asteroid;
	
	AsteroidsScene(QMainWindow* parent, std::vector<Asteroid*> asteroids);	
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
	std::vector<Asteroid*> m_asteroids;	
}

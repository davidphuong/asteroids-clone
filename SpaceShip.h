#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "VisibleGameObject.h"
#include "Bullet.h"

#include <vector>

class SpaceShip : public VisibleGameObject {
    public:
        SpaceShip();
        ~SpaceShip();

        virtual void update();
        void draw(sf::RenderWindow& window);

    private:
        double m_velocity_limit;

        float compute_x_component(float angle);
        float compute_y_component(float angle);

        std::vector<Bullet*> m_bullets;

        sf::Clock m_clock;
};

#endif

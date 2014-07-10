#ifndef BULLET_H
#define BULLET_H

#include "VisibleGameObject.h"

class Bullet : public VisibleGameObject {
    public:
        Bullet(float angle, sf::Vector2f position);
        virtual void update();

    private:
        float m_x_vel;
        float m_y_vel;
};

#endif

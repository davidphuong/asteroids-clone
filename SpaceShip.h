#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "VisibleGameObject.h"

class SpaceShip : public VisibleGameObject {
    public:
        SpaceShip();

        virtual void update();

    private:
        double m_velocity_limit;

        float compute_x_component(float angle);
        float compute_y_component(float angle);
};

#endif

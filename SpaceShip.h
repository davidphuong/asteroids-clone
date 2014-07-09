#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "VisibleGameObject.h"

class SpaceShip : public VisibleGameObject {
    public:
        SpaceShip();

        virtual void update();
};

#endif

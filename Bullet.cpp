#include "Bullet.h"

#include <math.h>

Bullet::Bullet(float angle, sf::Vector2f position) {
    load("images/bullet.png");
    set_position(position.x, position.y);

    angle += 90;
    m_x_vel = -1.0 * static_cast<float>(cos(angle * (3.14159265 / 180)));
    m_y_vel = -1.0 * static_cast<float>(sin(angle * (3.14159265 / 180)));
}

void Bullet::update() {
    m_sprite.move(m_x_vel * 3, m_y_vel * 3);
}

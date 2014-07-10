#include "SpaceShip.h"

#include <math.h>

SpaceShip::SpaceShip() :
    m_velocity_limit(1)
{

}

void SpaceShip::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_sprite.rotate(-1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_sprite.rotate(1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        float rotation = m_sprite.getRotation();
        rotation += 90;

        m_velocity.x += -1 * compute_x_component(rotation) * 0.1;
        m_velocity.y += compute_y_component(rotation) * 0.1;

    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

    }

    if (m_velocity.x > m_velocity_limit) {
        m_velocity.x = m_velocity_limit;
    } else if (m_velocity.x < -m_velocity_limit) {
        m_velocity.x = -m_velocity_limit;
    }

    if (m_velocity.y > m_velocity_limit) {
        m_velocity.y = m_velocity_limit;
    } else if (m_velocity.y < -m_velocity_limit) {
        m_velocity.y = -m_velocity_limit;
    }

    m_sprite.move(m_velocity.x, m_velocity.y);
}

float SpaceShip::compute_x_component(float angle) {
    return static_cast<float>(cos(angle * (3.14159265 / 180)));
}

float SpaceShip::compute_y_component(float angle) {
    return -1.0 * static_cast<float>(sin(angle * (3.14159265 / 180)));
}

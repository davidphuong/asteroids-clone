#include "SpaceShip.h"

SpaceShip::SpaceShip() :
    m_velocity_limit(2)
{

}

void SpaceShip::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_velocity.x -= 0.1;   
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_velocity.x += 0.1;   
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_velocity.y -= 0.1;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_velocity.y += 0.1;
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

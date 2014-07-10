#include "SpaceShip.h"

#include <math.h>
#include <iostream>

SpaceShip::SpaceShip() :
    m_velocity_limit(1)
{

}

SpaceShip::~SpaceShip() {
    for (unsigned int i = 0; i < m_bullets.size(); i++) {
        delete m_bullets[i];
    }
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
        // Do nothing.
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_bullets.push_back(new sf::RectangleShape);
        // m_bullets[m_bullets.size() - 1]->setSize(sf::Vector2f(20, 0));
        m_bullets[m_bullets.size() - 1]->setSize(sf::Vector2f(10, 1));
        m_bullets[m_bullets.size() - 1]->setRotation(m_sprite.getRotation() + 180);
        m_bullets[m_bullets.size() - 1]->setFillColor(sf::Color::Red);
        m_bullets[m_bullets.size() - 1]->setOutlineColor(sf::Color::Red);
        m_bullets[m_bullets.size() - 1]->setOutlineThickness(2);
        m_bullets[m_bullets.size() - 1]->setPosition(50, 50);
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

void SpaceShip::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);

    for (unsigned int i = 0; i < m_bullets.size(); i++) {
        m_bullets[i]->move(4, 0);
        window.draw(*m_bullets[i]);
    }
}

float SpaceShip::compute_x_component(float angle) {
    return static_cast<float>(cos(angle * (3.14159265 / 180)));
}

float SpaceShip::compute_y_component(float angle) {
    return -1.0 * static_cast<float>(sin(angle * (3.14159265 / 180)));
}

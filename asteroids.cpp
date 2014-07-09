#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SpaceShip.h"
#include "Constant.h"
#include "GameObjectManager.h"

void process_input();
void update();
void render();

sf::RenderWindow main_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroids!");
GameObjectManager game_object_manager;

bool end_game = false;

int main(int argc, char* argv[]) {
    main_window.setFramerateLimit(60);

    // Initializing game objects.
    SpaceShip* ship = new SpaceShip;
    ship->load("images/ship.png");
    ship->set_position(SCREEN_WIDTH / 2, SCREEN_HEIGHT - ship->get_height());
    game_object_manager.add("ship", ship);

    // Game loop
    while (main_window.isOpen() && end_game == false) {
        process_input();
        update();
        render();
    }

    return 0;
}

void process_input() {
    sf::Event event;
    if (main_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            main_window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                main_window.close();
            }
        }
    }
}

void update() {
    game_object_manager.update_all();
}

void render() {
    main_window.clear(sf::Color(255, 255, 255));
    game_object_manager.draw_all(main_window);
    main_window.display();
}

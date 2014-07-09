#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Constant.h"

void process_input();
void update();
void render();

sf::RenderWindow main_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroids!");

bool end_game = false;

int main(int argc, char* argv[]) {
    main_window.setFramerateLimit(60);

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

}

void render() {
    main_window.clear(sf::Color(255, 255, 255));
    main_window.display();
}

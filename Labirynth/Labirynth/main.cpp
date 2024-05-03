#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Labirynth");

    sf::Texture grass_texture;
    if (!grass_texture.loadFromFile("D:/Documents/Projects/PUT/Informartion_engineering_2/Labirynth/Labirynth/images/wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    //sf::Sprite sprite;
    //sprite.setTexture(grass_texture);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        // end the current frame
        window.display();
    }

    return 0;
}

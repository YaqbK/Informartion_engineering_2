#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Labirynth");

    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    sf::Texture grass_texture;
    if (!grass_texture.loadFromFile("D:/Documents/Projects/PUT/Informartion_engineering_2/Labirynth/Labirynth/images/grass.png")) {return 1;}
    grass_texture.setRepeated(true);
    std::unique_ptr<sf::Sprite> grass = std::make_unique<sf::Sprite>();
    grass->setTexture(grass_texture);
    grass->setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    shapes.emplace_back(std::move(grass));

    sf::Texture wall_texture;
    if (!wall_texture.loadFromFile("D:/Documents/Projects/PUT/Informartion_engineering_2/Labirynth/Labirynth/images/wall.png")) {return 1;}
    wall_texture.setRepeated(true);
    int numOfWalls = 10;
    std::vector<std::unique_ptr<sf::Sprite>> walls;
    for(int i=0; i<numOfWalls; i++){
        walls.emplace_back(std::make_unique<sf::Sprite>());
        walls[i]->setTexture(wall_texture);
    }
    walls[0]->setTextureRect(sf::IntRect(0, 0, window.getSize().x, 28));

    walls[1]->setTextureRect(sf::IntRect(0, 0, window.getSize().x, 28));
    walls[1]->setPosition(0, window.getSize().y-28);

    walls[2]->setTextureRect(sf::IntRect(9, 0, 28, window.getSize().y-56));
    walls[2]->setPosition(0,28);

    walls[3]->setTextureRect(sf::IntRect(9, 0, 28, (window.getSize().y-100)/2));
    walls[3]->setPosition(window.getSize().x-28,28);

    walls[4]->setTextureRect(sf::IntRect(9, 0, 28, (window.getSize().y-100)/2-28));
    walls[4]->setPosition(window.getSize().x-28,(window.getSize().y-100)/2+100);

    for (int i = 0; i < 5; ++i) {
        shapes.emplace_back(std::move(walls[i]));
    }

    sf::Texture guy_texture;
    if (!guy_texture.loadFromFile("D:/Documents/Projects/PUT/Informartion_engineering_2/Labirynth/Labirynth/images/guy.png")) {return 1;}
    std::unique_ptr<sf::Sprite> guy = std::make_unique<sf::Sprite>();
    guy->setTexture(guy_texture);
    guy->setPosition(50,50);
    shapes.emplace_back(std::move(guy));



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
        for(auto &s : shapes) { window.draw(*s); }

        // end the current frame
        window.display();
    }

    return 0;
}

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
    int numOfWalls = 16;
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

    walls[5]->setTextureRect(sf::IntRect(9, 0, 170, 28));
    walls[5]->setPosition(28, 430);

    walls[6]->setTextureRect(sf::IntRect(9, 0, 28, 280));
    walls[6]->setPosition(120, 27);

    walls[7]->setTextureRect(sf::IntRect(9, 0, 340, 28));
    walls[7]->setPosition(148, 110);

    walls[8]->setTextureRect(sf::IntRect(9, 0, 28, 338));
    walls[8]->setPosition(300, 240);

    walls[9]->setTextureRect(sf::IntRect(9, 0, 60, 28));
    walls[9]->setPosition(328, 300);

    walls[10]->setTextureRect(sf::IntRect(9, 0, 28, 200));
    walls[10]->setPosition(488, 110);

    walls[11]->setTextureRect(sf::IntRect(9, 0, 100, 28));
    walls[11]->setPosition(488, 310);

    walls[12]->setTextureRect(sf::IntRect(9, 0, 28, 108));
    walls[12]->setPosition(450, 470);

    walls[13]->setTextureRect(sf::IntRect(9, 0, 240, 28));
    walls[13]->setPosition(450, 442);

    walls[14]->setTextureRect(sf::IntRect(9, 0, 28, 328));
    walls[14]->setPosition(665, 120);

    for (int i = 0; i < 15; ++i) {
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

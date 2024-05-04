#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <SFML/Window/Mouse.hpp>


std::vector<int> player_move(const int& x, const int& y, const int& movement){
    int mouse_x = sf::Mouse::getPosition().x;
    int mouse_y = sf::Mouse::getPosition().y;
    int mx, my;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (mouse_x > x + 43 && mouse_y > y + 69){
            mx = (mouse_x - (x + 43) < 20) ? movement : 0;
            my = (mouse_y - (y + 69) < 20) ? movement : 0;
        }
        else if (mouse_x < x && mouse_y < y){
            mx = (x - mouse_x < 20) ? movement : 0;
            my = (y - mouse_y < 20) ? movement : 0;
        }
        else if (mouse_x < x && mouse_y > y + 69){
            mx = (x - mouse_x < 20) ? movement : 0;
            my = (mouse_y - (y + 69) < 20) ? movement : 0;
        }
        else if (mouse_x > x + 43 && mouse_y < y){
            mx = (mouse_x - (x + 43) < 20) ? movement : 0;
            my = (y - mouse_y < 20) ? movement : 0;
        }
        else
            return {0,0};

        return {mx,my};

    }
    return {0,0};
}

int main() {
    sf::Clock clock;

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
    int numOfWalls = 15;
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

    for (int i = 0; i < numOfWalls; ++i) {
        shapes.emplace_back(std::move(walls[i]));
    }

    sf::Texture guy_texture; // 43x69
    if (!guy_texture.loadFromFile("D:/Documents/Projects/PUT/Informartion_engineering_2/Labirynth/Labirynth/images/guy.png")) {return 1;}
    guy_texture.setRepeated(true);
    std::unique_ptr<sf::Sprite> guy = std::make_unique<sf::Sprite>();
    guy->setTexture(guy_texture);
    guy->setPosition(50,50);
    //shapes.emplace_back(std::move(guy));
    std::unique_ptr<sf::FloatRect> guy_bounds = std::make_unique<sf::FloatRect>(guy->getGlobalBounds());


    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        int mx = player_move((guy->getPosition().x), guy->getPosition().y, 40*dt)[0];
        int my = player_move((guy->getPosition().x), guy->getPosition().y, 40*dt)[1];

        guy->move(mx, my);

        // draw everything here...
        for(auto &s : shapes) { window.draw(*s); }
        window.draw(*guy);

        // end the current frame
        window.display();
    }

    return 0;
}

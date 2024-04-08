#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

    class CustomRectangleShape : public sf::RectangleShape{

public:

    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f position){
        setPosition(position);
        setSize(size);
        setFillColor(sf::Color(95, 55, 230));
    }
    void setSpeed(const int &Vspeed, const int &Hspeed, const int &Rspeed){
        Xspeed_ = Vspeed;
        Yspeed_ = Hspeed;
        Rspeed_ = Rspeed;
    }
    void animate(float &dt, int y, int x){
        move(Xspeed_*dt, Yspeed_*dt);
        rotate(Rspeed_*dt);
         sf::FloatRect rec_bounds = getGlobalBounds();
        if(rec_bounds.top <= 0){
            Xspeed_ = abs(Xspeed_);
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        if(rec_bounds.top + rec_bounds.height >= y){
            Xspeed_ = abs(Xspeed_) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        if(rec_bounds.left <= 0 ){
            Yspeed_ = abs(Yspeed_);
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }

        if(rec_bounds.left + rec_bounds.width >= x){
            Yspeed_ = abs(Yspeed_) * -1;
            setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
    }
    void move_up() {Xspeed_ = abs(Xspeed_)*-1;}
    void move_down() {Xspeed_ = abs(Xspeed_);}
    void move_right() {Yspeed_ = abs(Yspeed_);}
    void move_left() {Yspeed_ = abs(Yspeed_)*-1;}

    void moveInDirection(){

        // one way
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//            move_up();
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//            move_down();
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//            move_right();
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
//            move_left();
//        }

        // the other
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            Yspeed_ = -150;
            Xspeed_ = 0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            Yspeed_ = 150;
            Xspeed_ = 0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            Yspeed_ = 0;
            Xspeed_ = 150;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            Yspeed_ = 0;
            Xspeed_ = -150;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            Yspeed_ = -150;
            Xspeed_ = 150;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            Yspeed_ = -150;
            Xspeed_ = -150;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            Yspeed_ = 150;
            Xspeed_ = 150;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            Yspeed_ = 150;
            Xspeed_ = -150;
        }
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            Yspeed_ = 0;
            Xspeed_ = 0;
        }

    }
    void ObjectCollision(sf::RectangleShape other_object){
        sf::FloatRect object2 = other_object.getGlobalBounds();
        sf::FloatRect object1 = getGlobalBounds();
        if (object1.top <= object2.top + object2.height && object1.top + object1.height > object2.top){
            Yspeed_ = abs(Yspeed_);
            std::cout << "top" << std::endl;
        }
        if (object1.left <= object2.left + object2.width && object1.top + object1.width > object2.left + object1.width){
            Xspeed_ = abs(Xspeed_);
            std::cout << "left" << std::endl;
        }
        if (object1.top + object1.height >= object2.top && object1.top < object2.top + object2.height){
            Yspeed_ = abs(Yspeed_)*-1;
            std::cout << "bottom" << std::endl;
        }
        if (object1.left + object1.width >= object2.left && object1.left < object2.left){
            Yspeed_ = abs(Yspeed_)*-1;
            std::cout << "right" << std::endl;

        }

    }
private:

    int Xspeed_ = 0;
    int Yspeed_ = 0;
    int Rspeed_ = 0;
};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));

    rectangle.setPosition(500.0, 400.0);

    rectangle.setFillColor(sf::Color(100, 50, 250));
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    triangle.setPosition(600.0, 100.0);
    sf::Clock clock;

    int rectangle_velocity_x = 50;
    int rectangle_velocity_y = 200;
    int rectangle_angular_velocity = 10;
    //    int rec2_velocity_x = 100;
    //    int rec2_velocity_y = 100;

    bool flag_y = false;
    bool flag_x = false;

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rec2(size, position);
    rec2.setSpeed(150, 150, 0);

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        //        sf::FloatRect rec2_bounds = rec2.getGlobalBounds();

        if(rectangle_bounds.top <= 0){
            rectangle_velocity_y = abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if(rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y){
            rectangle_velocity_y = abs(rectangle_velocity_y) * -1;
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if(rectangle_bounds.left <= 0 ){
            rectangle_velocity_x = abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        if(rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x){
            rectangle_velocity_x = abs(rectangle_velocity_x) * -1;
            rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
        }
        rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);
        rectangle.rotate(rectangle_angular_velocity*dt);
        rec2.animate(dt, window.getSize().y, window.getSize().x);

        rec2.moveInDirection();
        // rec2.ObjectCollision(rectangle); it's bugged and not needed in the final assignment so i'm leaving it for now commented
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
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(rec2);
        // end the current frame
        window.display();
    }
    return 0;
}

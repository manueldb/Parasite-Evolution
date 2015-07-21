#include<iostream>
#include <SFML/Graphics.hpp>

class Player{
public:
    int x = 300;
    int y = 495;
    int x_speed = 1;
    sf::Sprite sprite;
    sf::Texture texture1;
    Player();

    bool moving_right = false;
    bool moving_left = false;
    bool moving_up = false;
    bool moving_down = false;

    void moveDetection();
};

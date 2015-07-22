#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>

class Player{
public:
    int x = 400;
    int y = 495;
    int x_speed = 1;
    sf::Sprite sprite;
    sf::Texture textures[7];
    Player();

    bool moving_right = false;
    bool moving_left = false;
    bool moving_up = false;
    bool moving_down = false;

    void moveDetection();
};

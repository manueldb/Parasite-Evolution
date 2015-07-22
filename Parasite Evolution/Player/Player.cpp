#include "Player.hpp"

Player::Player(){
    if (!textures[0].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(0, 10, 20, 11)))
    {
        // error...
    }
    if (!textures[1].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(20, 10, 40, 11)))
    {
        // error...
    }
    if (!textures[2].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(40, 10, 60, 11)))
    {
        // error...
    }
    if (!textures[3].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(60, 10, 80, 11)))
    {
        // error...
    }
    if (!textures[4].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(80, 10, 100, 11)))
    {
        // error...
    }
    if (!textures[5].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(100, 10, 120, 11)))
    {
        // error...
    }
    if (!textures[6].loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(120, 10, 140, 11)))
    {
        // error...
    }

    sprite.setTexture(textures[1]);
    sprite.setScale(4.f,4.f);
}

void Player::moveDetection(){
    if(moving_right) x+=x_speed;
    if(x >= 400){
        if(moving_left) x-=x_speed;
    }
}

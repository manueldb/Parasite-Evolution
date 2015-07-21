#include "Player.hpp"

Player::Player(){
    if (!texture1.loadFromFile("images/parasite/parasite_moving.png", sf::IntRect(0, 10, 20, 11)))
    {
        // error...
    }
    sprite.setTexture(texture1);
    sprite.setScale(4.f,4.f);
}

void Player::moveDetection(){
    if(moving_right) x+=x_speed;
    if(moving_left) x-=x_speed;
}

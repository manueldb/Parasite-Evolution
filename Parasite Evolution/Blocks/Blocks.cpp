#include "Blocks.hpp"


Stone::Stone(){
    if (!texture.loadFromFile("images/stone.png"))
    {
        // error...
    }
    sprite.setTexture(texture);
    sprite.setScale(2.f,2.f);
}

void Stone::reTexture(){
    if (!texture.loadFromFile("images/stone.png"))
    {
        // error...
    }
    sprite.setTexture(texture);
    sprite.setScale(2.f,2.f);
}

bool Block::collision(int x, int y){
    return x > this->x && x < this->x + side && y > this->y && y < this->y + side;
}

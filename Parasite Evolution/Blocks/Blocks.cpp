#include "Blocks.hpp"


Stone::Stone(){
    if (!texture.loadFromFile("images/stone.png"))
    {
        // error...
    }
    sprite.setTexture(texture);
    sprite.setScale(2.f,2.f);
}

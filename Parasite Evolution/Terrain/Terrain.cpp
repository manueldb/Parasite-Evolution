#include "Terrain.hpp"

Terrain::Terrain(){
    int x;
    int y = 536;
    for(Stone stone : stones){
        stone.sprite.setPosition(x, y);
        x+=64;
    }
}

void Terrain::draw(sf::Window window){
    for(Stone stone : stones){
        window.draw(stone.sprite);
    }
}

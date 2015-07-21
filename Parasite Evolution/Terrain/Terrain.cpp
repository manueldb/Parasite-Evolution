#include "Terrain.hpp"

Terrain::Terrain(){
    stones.resize(13);
}

void Terrain::createStones(int new_number_blocks){
    stones.resize(new_number_blocks);
    int x;
    int y = 536;
    for(int i = 0; i < stones.size(); i++){
        stones[i].sprite.setPosition(x, y);
        x+=64;
    }
}

void Terrain::draw(sf::RenderWindow& window){
    createStones(14);
    for(int i = 0; i < stones.size(); i++){
        window.draw(stones[i].sprite);
    }
}

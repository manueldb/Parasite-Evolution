#include "Terrain.hpp"

/*
    The idea is to generate the blocks as the player moves through the world.
    Thus, we have to be able to resize the stones vector and set the positions of the new elements.
    Unfortunately, when I try to use the createStones function, which is suposed to do this, the blocks
    are all white... I think...
    I am going to create the player physics to be able to test this bug better, while moving through the world
*/
Terrain::Terrain(){
    stones.resize(13);
    int x = 0;
    int y = 536;
    for(int i = 0; i < stones.size(); i++){
        stones[i].sprite.setPosition(x, y);
        x+=64;
    }
}

void Terrain::createStones(int new_number_blocks){
    int old_number_blocks = stones.size();
    stones.resize(new_number_blocks);
    int x = 64*old_number_blocks;
    int y = 536;
    for(int i = 0; i < old_number_blocks; i++){
        stones[i].reTexture();
    }
    for(int i = old_number_blocks; i < new_number_blocks; i++){
        stones[i].sprite.setPosition(x, y);
        x+=64;
    }
}

void Terrain::draw(sf::RenderWindow& window){
    for(int i = 0; i < stones.size(); i++){
        window.draw(stones[i].sprite);
    }
}

int Terrain::getGreatestX(){
    return stones.size()*64;
}

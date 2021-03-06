#include "Terrain.hpp"

Terrain::Terrain(){
    stones.resize(14);
    int x = 0;
    int y = 536;
    for(int i = 0; i < stones.size(); i++){
        if(x == 64){
            stones[i].sprite.setPosition(x,x);
            createVerticalStones(stones[i]);
        }
        else{
            if(!stones[i].vertical){
                stones[i].sprite.setPosition(x,y);

            }
        }
        x+=64;
    }
}

void Terrain::createStones(int new_number_blocks, int player_x){
    int old_number_blocks = stones.size();
    int x = player_x;
    stones.resize(new_number_blocks);
    int y = 536 - 64 * (rand() % 3);
    for(int i = 0; i < old_number_blocks; i++){
        stones[i].reTexture();
    }
    for(int i = old_number_blocks; i < new_number_blocks; i++){
        stones[i].sprite.setPosition(x, y);
        createVerticalStones(stones[i]);
    }
}

void Terrain::createVerticalStones(Stone stone){
    int number_vertical_stones = (int)((600 - (stone.y + stone.side))/stone.side);
    int old_number_stones = stones.size();
    stones.resize(old_number_stones + number_vertical_stones);
    for(int i = 0; i < old_number_stones; i++){
        stones[i].reTexture();
    }
    int y = 536;
    int x = stone.x+64;
    for(int i = old_number_stones; i < stones.size(); i++){
        stones[i].vertical = true;
        stones[i].sprite.setPosition(x, y);
        y-=64;
    }
}

void Terrain::draw(sf::RenderWindow& window){
    for(int i = 0; i < stones.size(); i++){
        window.draw(stones[i].sprite);
    }
}

int Terrain::getGreatestX(){
    int x_max = 0;
    for(int i = 0; i < stones.size(); i++){
        if(stones[i].x > x_max){
            x_max = stones[i].x;
        }
    }
    return x_max;
}

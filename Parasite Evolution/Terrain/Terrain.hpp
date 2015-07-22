#include<iostream>
#include <SFML/Graphics.hpp>
#include "../Blocks/Blocks.hpp"
#include<vector>
#include <cstdlib>

using namespace std;

class Terrain{
public:
    int number_blocks = 13;
    std::vector<Stone> stones;
    Terrain();
    void createStones(int);
    void draw(sf::RenderWindow&);
    int getGreatestX();
};

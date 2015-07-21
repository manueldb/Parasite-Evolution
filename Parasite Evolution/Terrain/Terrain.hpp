#include<iostream>
#include <SFML/Graphics.hpp>
#include "../Blocks/Blocks.hpp"

class Terrain{
public:
    Stone stones[13];
    Terrain();
    void draw(sf::Window);
};

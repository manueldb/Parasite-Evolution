#include<iostream>
#include <SFML/Graphics.hpp>

class Block{
public:
    int x;
    int y;
    int side = 64;
    sf::Sprite sprite;
    sf::Texture texture;
};

class Stone : public Block{
public:
    Stone();
};

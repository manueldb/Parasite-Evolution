#include<iostream>
#include <SFML/Graphics.hpp>

class Block{
public:
    int x;
    int y;
    int side = 64;
    sf::Sprite sprite;
    sf::Texture texture;

    bool collision(int, int);
};

class Stone : public Block{
public:
    Stone();
    void reTexture();
};

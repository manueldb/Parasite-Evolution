#include "Main.hpp"

int main(){

    //initialize window
    sf::RenderWindow window(sf::VideoMode(800,600), "Parasite Evolution");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(300, 100));
    //----//

    //initialize stone block
    Stone stone;
    //----//

    //game loop
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            //Close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }

        window.clear(sf::Color(20,180,180));
        window.draw(stone.sprite);
        window.display();
    }
    //----//

    return 0;
}

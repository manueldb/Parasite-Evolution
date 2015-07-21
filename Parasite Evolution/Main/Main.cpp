#include "Main.hpp"

int main(){
    //initialize terrain
    Terrain terrain;
    terrain.createStones(terrain.number_blocks);
    //----//

    //initialize player
    Player parasite;
    //----//

    //initialize window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Parasite Evolution");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(300, 100));
    //----//

    //game loop
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            //Close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Right){
                    parasite.moving_right = true;
                }
                if(event.key.code == sf::Keyboard::Left){
                    parasite.moving_left = true;
                }
                if(event.key.code == sf::Keyboard::Up){
                    parasite.moving_up = true;
                }
                if(event.key.code == sf::Keyboard::Down){
                    parasite.moving_down = true;
                }
            }
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Right){
                    parasite.moving_right = false;
                }
                if(event.key.code == sf::Keyboard::Left){
                    parasite.moving_left = false;
                }
                if(event.key.code == sf::Keyboard::Up){
                    parasite.moving_up = false;
                }
                if(event.key.code == sf::Keyboard::Down){
                    parasite.moving_down = false;
                }
            }


        }

        window.clear(sf::Color(18,4,51));

        //draw terrain
        terrain.draw(window);
        //----//

        //draw parasite
        parasite.moveDetection();
        parasite.sprite.setPosition(parasite.x, parasite.y);
        window.draw(parasite.sprite);
        //----//

        window.display();
    }
    //----//

    return 0;
}

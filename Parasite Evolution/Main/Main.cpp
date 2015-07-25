#include "Main.hpp"

int main(){
    int counter = 0;
    bool create = false;
    //initialize terrain
    Terrain terrain;
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

    //initialize view
    sf::View view(sf::Vector2f(400, 300), sf::Vector2f(800, 600));
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
        cout << "Size - " << terrain.stones.size() << endl;
        cout << "parasite.x - " << parasite.x << endl;
        cout << "create - " << create << endl;
        //----//

        //ugly generation
        if(parasite.x % 64 == 0){
            create = true;
        }else{create = false;}

        if(create){terrain.createStones(terrain.stones.size()+1, parasite.x+400);}
        //----//

        //draw parasite
        parasite.moveDetection();
        parasite.sprite.setPosition(parasite.x, parasite.y);
        window.draw(parasite.sprite);
        //----//

        //view
        view.setCenter(parasite.x, parasite.y - 195);
        /*if(terrain.getGreatestX() - parasite.x < 400){
            terrain.createStones(terrain.stones.size()+1);
        }*/
        window.setView(view);
        //----//

        window.display();
    }
    //----//

    return 0;
}


/*
TODO TOMORROW

make a view - 5 min --------__> DONE

player collision detection with blocks - 20 min ----> DONE

end terrain generation algorithm (__destroy that bug__ -- > DESTROYED), with the noise function - 3 h ------> BUG DESTROYED!! GENERATION WORKING!
^^^ ALMOST DONE... JUST NEED TO IMPLEMENT THE RANDOMNESS OF THE Y COORDINATE!
Another bug emerged -> trying to create vertical blocks images are corrupted -.-
vertical stones and createstones are compatible! yay
now just need to make random!!


BORING STUFF:

player animation while moving - 20 min

player --->crawl over blocks<--- or jump? maybe both? implement it - 30 min

*/

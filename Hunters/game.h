#ifndef GAME_H
#define GAME_H
#include "grid.h"
//#include <SFML/Graphics.hpp>
//#include "creature.h"

class Game{
public:
    //cstructor
    Game();

    //member func
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow window;
    Grid g;
};
#endif // GAME_H

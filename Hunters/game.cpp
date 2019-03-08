#include "game.h"

Game::Game(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Wenyuan's Sample Window!");
    window.setFramerateLimit(60);
}

//member func
void Game::Draw(){
    g.Draw(window);
}

void Game::update(){
    g.Show();
}

void Game::run(){
    while (window.isOpen()){
        processEvents();
        update();
        render(); //clear/draw/display
    }
}

void Game::render(){
    window.clear();
    Draw();
    window.display();

}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        // "close requested" event: we close the window
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
            else
                std::cout<<"left button?"<<std::endl;
            //mybox.setPosition(event.mouseButton.x,event.mouseButton.y);
            break;
        default:
            break;
        }
    }
}

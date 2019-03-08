#ifndef WALL_H
#define WALL_H
#include "creature.h"

class Wall:public Creature
{
public:
    Wall();
    Wall(int i, int j);
    void Show()const;
};

Wall::Wall():Creature(0,0,'W'){
    //cout<<endl<<"Wall Default Ctor Fired"<<endl;
    box.setFillColor(sf::Color::Red);
    box.setSize(sf::Vector2f(10,10));
}

Wall::Wall(int i, int j):Creature(i, j, 'W'){
    //cout<<endl<<"Wall 2nd Default Fired";
    //empty
    box.setFillColor(sf::Color::Red);
    box.setSize(sf::Vector2f(10,10));
}

void Wall::Show()const{
    cout<<'W';
}

#endif // WALL_H

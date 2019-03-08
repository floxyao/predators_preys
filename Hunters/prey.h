#ifndef PREY_H
#define PREY_H
#include "creature.h"

class Prey:public Creature
{
public:
    Prey();
    Prey(int i, int j);

    void Show()const;
    void Move(Creature* g[][MAX]);
    void breedPrey(Creature* g[][MAX]);
    int breedSteps=0;
};

Prey::Prey():Creature(0, 0, 'P'){
    //cout<<endl<<"Prey Default Ctor Fired"<<endl;
    //invokes the parent
    box.setFillColor(sf::Color::Green);
    box.setSize(sf::Vector2f(10,10));
}

Prey::Prey(int i, int j):Creature(i, j, 'P'){
    //cout<<endl<<"Prey 2nd Default Ctor Fired"<<endl;
    //empty
    box.setFillColor(sf::Color::Green);
    box.setSize(sf::Vector2f(10,10));
}

void Prey::Move(Creature* g[][MAX]){
    //cout<<endl<<"Prey Move Fired";
    int i=getRow(), j=getCol();
    if(moved==false){
        int rI=getRandom(-1,3), rJ=getRandom(-1,3);
        if(g[i+rI][j+rJ]==NULL){
            g[i+rI][j+rJ]=g[i][j];
            g[i][j]=NULL;
            setRow(i+rI); setCol(j+rJ);
        }
        else{
            //dont move
        }
        moved=true;
        breedSteps++;

        if(breedSteps>=3){
            breedPrey(g);
            breedSteps=0;
        }
    }
}

void Prey::breedPrey(Creature *g[][MAX]){
    for(int i=getRow()-1; i<=getRow()+1; i++){
        for(int j=getCol()-1; j<=getCol()+1; j++){
            if(g[i][j]==NULL){ //**check if theres a pointer there FIRST; before you were calling getFace from a NULL pointer
                g[i][j]=new Prey(i, j);
                return;
            }
        }
    }
    //cout<<endl<<"(Prey) checkNeighbors - No empty spaces";
}

void Prey::Show()const{
    cout<<'P';
}


#endif // PREY_H

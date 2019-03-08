#ifndef CREATURE_H
#define CREATURE_H
#include "grid.h"
#include "constants.h"
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

/*-------------------------------------------------------
 * Creature Class
 * This class is the parent class to Hunter, Prey, and Wall
 * Each child will inherit Creature's functions that apply
 * to all of them, but each child will have its own specialty
 --------------------------------------------------------*/
class Creature
{
public:
    Creature();
    Creature(int i, int j, char f); //x,y are position on grid, f is type

    virtual void Show()const;
    virtual void Move(Creature* g[][MAX]);
    virtual Creature* checkNeighbors(Creature* g[][MAX]);
    char getFace();

    //void MoveTo(int x int y) 
    void setRow(int i);
    void setCol(int j);
    int getRow();
    int getCol();
    void Reset();
    bool moved;
    friend ostream& operator << (ostream &out, const Creature &printMe);
    sf::RectangleShape box;

private:
    char face;
    int row;
    int col;
};

/*========Default Constructors=======*/
Creature::Creature(){
    //cout<<endl<<"Creature Default Fired"<<endl;
    //empty
}

Creature::Creature(int i, int j, char f){
    //cout<<endl<<"Creature 2nd Default fired"<<endl;
    row=i;
    col=j;
    face=f;
    moved=false;
}

/*=====Creature Member Functions=====*/
/* -------------------------------------------
 * Creature Move();
 * Pre: Takes a grid of creatures
 * Post: Virtual = calls every creature's move
 *       Reattaches/deattaches pointers accordingly
 *       Calls breedSteps to keep count (to die)
 *       Reproduces accordingly
 ---------------------------------------------*/
void Creature::Move(Creature* g[][MAX]){
    //cout<<endl<<"Creature Move Fired"<<endl;
    //empty
}

/* ------------------------------------------------
 * Creature checkNeighbors();
 * Pre: Takes no arguments
 * Post: Virtual calls subclasses check
 *       Checks perimeter for a creature pointer
 *       by a for loop that checks for NON NULL's
 *       when found, move to its position, cut off
 *       your own position. Update own i and j
 -------------------------------------------------*/
Creature* Creature::checkNeighbors(Creature* g[][MAX]){
    //cout<<endl<<"Check Neighbors Fired"<<endl;
}

/* ---------------------------------------------------
 * Creature Show();
 * Pre: Takes no arguments
 * Post: Virtual, calls each subclass's show
 ----------------------------------------------------*/
void Creature::Show()const{
    //cout<<endl<<"Creature Show Fired"<<endl;
    //empty
}


void Creature::Reset(){
    moved=false;
}
void Creature::setRow(int i){
    row=i;
}
void Creature::setCol(int j){
    col=j;
}
int Creature::getRow(){
    return row;
}
int Creature::getCol(){
    return col;
}
char Creature::getFace(){
    return face;
}
ostream& operator <<(ostream &out, const Creature &printMe){
    printMe.Show();
    return out;
}



#endif // CREATURE_H

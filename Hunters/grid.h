#ifndef GRID_H
#define GRID_H
#include "creature.h"
#include "hunter.h"
#include "prey.h"
#include "wall.h"
#include "constants.h"
#include "random.h"
#include <iostream>
//#include "SFML/Graphics.hpp"
using namespace std;

class Grid
{
public:
    Grid();

    //Big Three
    ~Grid();
    Grid(const Grid &other);
    Grid &operator = (const Grid &rhs);

    //Member Functions
    void InitGrid();
    void InitPrey();
    void InitHunter();
    void InitWall();
    void ShowPopulation();
    void Show()const;
    void Step();
    void Reset();
    void Draw(sf::RenderWindow& window);
    friend ostream& operator << (ostream &out, const Grid &printMe);

private:
    Creature* grid[MAX][MAX];
    //Creature*
    //where T is a creature pointer
    //creature* grid[MAX][MAX];
};

/*======Default Constructors======*/
Grid::Grid(){
    cout<<endl<<"Default Ctor Fired"<<endl;
    InitGrid();
    InitPrey();
    InitWall();
    InitHunter();
    //    grid[1][2]=new Prey(1,2);
    //    grid[2][1]=new Prey(2,1);
    //    grid[3][3]=new Prey(3,3);
    //    grid[2][2]=new Hunter(2,2);

}

/*==========Big Three===========*/
Grid::~Grid(){
    cout<<endl<<"Grid Destructor"<<endl;
    if(grid!=NULL){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                delete grid[i][j];
            }
        }
    }
}

Grid::Grid(const Grid &other){
    cout<<endl<<"Grid Copy Constructor"<<endl;
    if(grid!=NULL){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                delete grid[i][j];
            }
        }
    }
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grid[i][j]=other.grid[i][j];
        }
    }
}

Grid &Grid::operator = (const Grid &rhs){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grid[i][j]=rhs.grid[i][j];
        }
    }
}


/*======Grid Member Functions=====*/
/* --------------------------------------------------
 * Grid Step();
 * Pre: Takes no arguments
 * Post: Goes through array, finds NON-NULL ptrs
 *       Tells those ptrs to call their Move();
 *       Globally resets all creatures moved back to false
 ---------------------------------------------------*/
void Grid::Step(){
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]!=NULL){
                grid[i][j]->Move(grid);
            }
            else{
                //cout<<endl<<"Grid Step: Pointer wasn't "
                //            "found couting something"<<endl;
            }
        }
    }
    ShowPopulation();
    Reset();
}

/* -------------------------------------------------
 * Grid Show();
 * Pre: Takes no arguments
 * Post: Calls each of the creature's to show itself
 --------------------------------------------------*/
void Grid::Show()const{
    cout<<endl;
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]==NULL){
                cout<<". ";
            }
            else{
                cout<<*grid[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

ostream& operator << (ostream &out, const Grid &printMe){
    //cout<<endl<<"Grid << Op Fired"<<endl;
    printMe.Show();
    return out;
}

void Grid::InitGrid(){
    //cout<<endl<<"Grid Init Fired"<<endl;
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            grid[i][j]=NULL;
        }
    }
}

void Grid::InitHunter(){
    int numOfHunters=10;
    for(int i=0, j=0; i<=numOfHunters; i++, j++){
        int rI=getRandom(0,MAX), rJ=getRandom(0,MAX);
        if(grid[rI][rJ]==NULL){
            grid[rI][rJ]=new Hunter(rI, rJ);
        }
    }
}

void Grid::InitPrey(){
    for(int i=0; i<20; i++){
        for(int j=0; j<10; j++){
            int rI=getRandom(0,MAX), rJ=getRandom(0,MAX);
            if(grid[rI][rJ]==NULL){
                grid[rI][rJ]=new Prey(rI, rJ);
            }
        }
    }
}

void Grid::InitWall(){
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i==0 || j==0 || i==MAX-1 || j==MAX-1){
                grid[i][j]=new Wall(i, j);
            }
        }
    }
}

void Grid::Reset(){
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]!=NULL){
                grid[i][j]->Reset();
            }
        }
    }
}

void Grid::ShowPopulation(){
    int prey=0, hunter=0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(grid[i][j]!=NULL){
                if(grid[i][j]->getFace()=='P'){
                    prey++;
                }
                if(grid[i][j]->getFace()=='H'){
                    hunter++;
                }
            }
        }
    }
    cout<<"Hunter: "<<hunter<<" Prey: "<<prey;
}

void Grid::Draw(sf::RenderWindow &window){
    for (int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
                window.draw(grid[i][j]->box);
            }
    }
}



#endif // GRID_H

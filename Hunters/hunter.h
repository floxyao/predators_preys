#ifndef HUNTER_H
#define HUNTER_H
#include "creature.h"
#include "random.h"

class Hunter:public Creature
{
public:
    Hunter();
    Hunter(int i, int j);
    //Hunter::Hunter(int i, int j, char f, etc):Creature(i,j,f)
    //we invoke the parent cause we need the i j f to be initialized

    void Show()const;
    void Move(Creature *g[][MAX]);
    void ShowNumbers();
    void breedHunter(Creature* g[][MAX]);
    void Starve(Creature* g[][MAX]);
    int hunger=0;
    int breedSteps=0;
    bool hasEaten=false;
    Creature* pickRandom(Creature *prey[], int size);
    Creature* checkNeighbors(Creature *g[][MAX]);
};

Hunter::Hunter():Creature(0, 0, 'H'){
    //cout<<endl<<"Hunter Default Ctor Fired"<<endl;
    //invokes the parent
    box.setFillColor(sf::Color::Yellow);
    box.setSize(sf::Vector2f(10,10));

}

Hunter::Hunter(int i, int j):Creature(i, j, 'H'){
    //cout<<endl<<"Hunter 2nd Default Fired";
    box.setFillColor(sf::Color::Yellow);
    box.setSize(sf::Vector2f(10,10));
}

Creature* Hunter::checkNeighbors(Creature* g[][MAX]){
    //cout<<endl<<"Hunter checkNeighbors fired";
    Creature* foodList[8];
    int index=0;
    for(int i=getRow()-1; i<=getRow()+1; i++){
        for(int j=getCol()-1; j<=getCol()+1; j++){
            if(g[i][j]!=NULL){  //**check if theres a pointer there FIRST; before you were calling getFace from a NULL pointer
                if(g[i][j]->getFace()=='P'){
                    foodList[index]=g[i][j];
                    //g[i][j] is a creature pointer
                    //*g[i][j] is a creature (deref)
                    index++;
                }
            }
        }
    }
    if(index==0){
        return NULL;
    }
    return pickRandom(foodList, index);
}

Creature* Hunter::pickRandom(Creature* foodList[], int size){
    //cout<<endl<<"Entered pickRandom"<<endl;
    int randomNum=getRandom(0,size);
    //cout<<"Hunter::PickRandom: Here is my Random: "<<randomNum<<endl;
    return foodList[randomNum];
}

void Hunter::Move(Creature* g[][MAX]){
    //cout<<endl<<"Hunter Move fired";
    int i=getRow(), j=getCol();
    if(moved==false){ //Fires if the creature has not moved
        Creature* neighbor=g[i][j]->checkNeighbors(g); //Checks perimeter for Prey
        if(neighbor!=NULL){                            //If neighbor is not NULL, it is either 'P', 'H', or 'W'
            if(neighbor->getFace()=='P'){              //If the neighbor is a Prey, then eat
                int r = neighbor->getRow(),
                    c = neighbor->getCol();
                g[r][c]=g[i][j];      //Eat, attach to new position
                g[i][j]=NULL;         //Deattach old position
                setRow(r); setCol(c); //Update position
                hasEaten=true;        //Update hunger
                hunger=0;
            }
        }
        else{
            int rI=getRandom(-1,3),
                rJ=getRandom(-1,3);  //If no neighbors are around, move randomly
            if(g[i+rI][j+rJ]==NULL){ //If random point choisen is empty, move to that space
                g[i+rI][j+rJ]=g[i][j];
                g[i][j]=NULL;
                setRow(i+rI); setCol(j+rJ);
                hunger++;
                if(hunger>=3){
                    hasEaten=false;
                }
                moved=true;
            }
            else{
                moved=true;
                //No spots available, don't move
            }
        }
        //moved=true;

        breedSteps++;
        if(breedSteps>3 && hasEaten==false){
            //cout<<endl<<"HUNTERS DIE";
            Starve(g);
        }
        if(breedSteps>8){
            //cout<<endl<<"HUNTERS BREED";
            breedHunter(g);
            breedSteps=0;
        }
    }
    else{
        //cout<<endl<<"Creature has moved"<<endl;
    }
}

void Hunter::breedHunter(Creature *g[][MAX]){
    for(int i=getRow()-1; i<=getRow()+1; i++){
        for(int j=getCol()-1; j<=getCol()+1; j++){
            if(g[i][j]==NULL){ //**check if theres a pointer there FIRST; before you were calling getFace from a NULL pointer
                g[i][j]=new Hunter(i, j);
                return;
            }
        }
    }
}

void Hunter::Starve(Creature *g[][MAX]){
    int i=getRow(), j=getCol();
    g[i][j]=NULL;
}

void Hunter::Show()const{
    //cout<<endl<<"Hunter Show Fired"<<endl;
    cout<<'H';
}




#endif // HUNTER_H

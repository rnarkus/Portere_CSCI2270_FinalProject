//Steven Porter
//Final Project
//Hoenigman
//Bubernak

#include "labrynth.h"
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>

using namespace std;
//initialize available moves so it can be used in buildLabyrinth
void availableMoves(node* x);

void Labyrinth::buildLabyrinth(){ //assigns all nodes to their respective positions, see attached document for map layout

    node* create = new node();
    create->point = "start";
    node* create1 = new node();
    create1->point = "1";
    node* create2 = new node();
    create2->point = "2";
    node* create3 = new node();
    create3->point = "3";
    node* create4 = new node();
    create4->point = "4";
    node* create5 = new node();
    create5->point = "5";
    node* create6 = new node();
    create6->point = "6";
    node* create7 = new node();
    create7->point = "7";
    node* create8 = new node();
    create8->point = "8";
    node* create9 = new node();
    create9->point = "9";
    node* createA = new node();
    createA->point = "A";
    node* createB = new node();
    createB->point = "B";
    node* createC = new node();
    createC->point = "C";
    node* createD = new node();
    createD->point = "D";
    node* createE = new node();
    createE->point = "E";
    node* createF = new node();
    createF->point = "F";
    node* createG = new node();
    createG->point = "G";
    node* createH = new node();
    createH->point = "H";
    node* createI = new node();
    createI->point = "I";
    node* createJ = new node();
    createJ->point = "J";
    node* createK = new node();
    createK->point = "K";
    node* createL = new node();
    createL->point = "L";
    node* createM = new node();
    createM->point = "M";
    node* createN = new node();
    createN->point = "N";
    node* createO = new node();
    createO->point = "O";
    node* createP = new node();
    createP->point = "P";
    node* createQ = new node();
    createQ->point = "Q";
    node* createR = new node();
    createR->point = "R";
    node* createS = new node();
    createS->point = "S";
    node* last_pos = new node();
    last_pos->point = "Last Position";
    create->next = create1;
    create1->right = create2;
    create1->left = create3;
    create1->prev = create;
    create3->right = create1;
    create2->left = create1;
    create3->next = create4;
    create4->prev = create3;
    create4->next = create5;
    create5->prev = create4;
    create5->right = createA;
    create5->left = create6;
    create6->right = create5;
    createA->left = create5;
    create6->left = create7;
    create7->prev = create9;
    create7->left = create8;
    create7->right = create6;
    create8->right = create7;
    create9->next = create7;
    //back to part A
    createA->next = createL;
    createL->prev = createA;
    createA->prev = createB;
    createB->next = createA;
    createA->right = createC;
    createC->left = createA;
    createC->prev = createD;
    createD->next = createC;
    createC->right = createG;
    createG->left = createC;
    createC->next = createE;
    createE->prev = createC;
    createE->right = createF;
    createF->left = createE;
    //back to part G
    createG->right = createH;
    createH->left = createG;
    createH->next = createJ;
    createJ->prev = createH;
    createH->prev = createI;
    createI->next = createH;
    createJ->next = createK;
    createK->prev = createJ;
    //back to part L
    createL->next = createM;
    createM->prev = createL;
    createM->left = createN;
    createN->right = createM;
    createN->left = createO;
    createO->right = createN;
    createN->next = createP;
    createP->prev = createN;
    createP->next = createQ;
    createQ->prev = createP;
    createQ->left = createR;
    createR->right = createQ;
    createR->next = last_pos;
    last_pos->prev = createR;
    createR->prev = createS;
    createS->next = createR;
    //treasure placement
    createB->treasure = "Green Gem";
    create7->treasure = "Blue Gem";
    createF->treasure = "Red Gem";
    last_pos->treasure = "Butter Knife";
    create1->treasure = "Marker";
    createA->treasure = "Marker";
    createK->treasure = "Marker";
    createN->treasure = "Marker";
    create9->treasure = "Marker";
    createR->treasure = "Marker";
    //create the labyrinth start point
    start = create;
    availableMoves(start);

}


void availableMoves(node* x){//gives the available moves based on the node sent it
    if(x->visited == false){
        x->visited = true;
        if(x->next != NULL){
            x->available_moves+=" Forward";
            availableMoves(x->next);
        }
        if(x->prev != NULL){
            x->available_moves+=" Backward";
            availableMoves(x->prev);
        }
        if(x->left!=NULL){
            x->available_moves+=" Left";
            availableMoves(x->left);
        }
        if(x->right!=NULL){
            x->available_moves+= " Right";
            availableMoves(x->right);
        }
    }
}

node* Labyrinth::returnStartingPos(){//returns the start point of the maze, a private variable
    return start;
}

bool pouch::hasAllGems(){//returns t/f if player has all the gems
    bool hasGems = true;
    int x = 0;
    while(x <3){
        if(gems[x].empty())
            hasGems = false;
        x++;
    }
    return hasGems;
}
void pouch::printPouch(){//prints out everything in the pouch
    cout<<"Available Markers: "<<markerCount<<endl;
    cout<<"Gem's Found: "<<gemCount<<endl;
    cout<<"Gem's Collected: ";
    for(int i = 0; i<3;i++){
        if (i == 2)
            cout<<gems[i]<<", ";
        else
            cout<<gems[i];
    }
    cout<<endl;

}
void player::addGem(string gemType, pouch* bag){//adds the gem that's been found to your "pouch"
    int i = 0;
    while(i<3){
        if(bag->gems[i].empty()){
            bag->gems[i] = gemType;
            bag->gemCount++;
            break;
        }
        else
            i++;
    }
}

void player::moveBackward(){//movement backward
    if(position->prev != NULL){
        position = position->prev;
        if(position->treasure == "Red Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Red Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Green Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Green Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Blue Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Blue Gem"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Butter Knife"){
            weapon = position->treasure;
            cout<<"A butter knife? I wonder what I can do with this..."<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Marker"){
            bag->markerCount++;
            cout<<"Picked up a Marker"<<endl;
            position->treasure = "";
        }
        if(position->marker == true){
            cout<<"You're back on a marker you've placed, here's what it says: "<<endl;
            cout<<position->markerTxt<<endl;
        }
    }
    else
        cout<<"How about you try that again"<<endl;
}
void player::moveForward(){//movement forward
    if(position->next != NULL){
        position = position->next;
        if(position->treasure == "Red Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Red Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Green Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Green Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Blue Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Blue Gem"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Butter Knife"){
            weapon = position->treasure;
            cout<<"A butter knife? I wonder what I can do with this..."<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Marker"){
            bag->markerCount++;
            cout<<"Picked up a Marker"<<endl;
            position->treasure = "";
        }
        if(position->marker == true){
            cout<<"You're back on a marker you've placed, here's what it says: "<<endl;
            cout<<position->markerTxt<<endl;
        }
    }
    else
        cout<<"Are you sure you can go that way?"<<endl;
}
void player::moveLeft(){//movement left
    if(position->left != NULL){
        position = position->left;
                if(position->treasure == "Red Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Red Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Green Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Green Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Blue Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Blue Gem"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Butter Knife"){
            weapon = position->treasure;
            cout<<"A butter knife? I wonder what I can do with this..."<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Marker"){
            bag->markerCount++;
            cout<<"Picked up a Marker"<<endl;
            position->treasure = "";
        }
        if(position->marker == true){
            cout<<"You're back on a marker you've placed, here's what it says: "<<endl;
            cout<<position->markerTxt<<endl;
        }
    }
    else
        cout<<"Let's take another look at your moves..."<<endl;
}
void player::moveRight(){//movement right
    if(position->right != NULL){
        position = position->right;
                if(position->treasure == "Red Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Red Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Green Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Green Gem!"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Blue Gem"){
            addGem(position->treasure,bag);
            cout<<"You picked up the Blue Gem"<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Butter Knife"){
            weapon = position->treasure;
            cout<<"A butter knife? I wonder what I can do with this..."<<endl;
            position->treasure = "";
        }
        if(position->treasure == "Marker"){
            bag->markerCount++;
            cout<<"Picked up a Marker"<<endl;
            position->treasure = "";
        }
        if(position->marker == true){
            cout<<"You're back on a marker you've placed, here's what it says: "<<endl;
            cout<<position->markerTxt<<endl;
        }

    }
    else
        cout<<"How about no."<<endl;
}
 void player::placeMarker(){//place a marker on the players position
    if(bag->markerCount>0)
    {
        bag->markerCount--;
        string x;
        cout<<"What would you like to write on the marker?"<<endl;
        cin.ignore();
        getline(cin,x);
        position->markerTxt = x;
        position->marker = true;
        cout<<"Marker has been placed"<<endl;
    }
    else{
        cout<<"You don't have any markers. Find them around the maze."<<endl;
    }
 }
 void player::printInventory(){//prints out everything the player has
 cout<<name<<"'s inventory:"<<endl;
 cout<<"Weapon: "<<weapon<<endl;
 bag->printPouch();
 }

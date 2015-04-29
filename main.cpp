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

void signPost(){

cout<<"-----------------------------------------"<<endl<<"|WELCOME TO THE LABYRINTH.               |"<<endl<<"|BE CAREFUL, I WISH YOU THE BEST OF LUCK!|"<<endl<<"-----------------------------------------"<<endl<<"                    |                   "<<endl<<"                    |                   "<<endl<<"                    |                   "<<endl<<"                    |                   "<<endl<<"                    |                   "<<endl<<"                    |                   "<<endl;
}

int main(){
    Labyrinth maze;
    maze.buildLabyrinth();
    bool running = true;
    string name;
    string response;
    cout<<"What is your player's name?"<<endl;
    getline(cin, name);
    player* one = new player(name,maze.returnStartingPos());
    cout<<"Hello, "<<one->name<<endl<<"Are you ready to enter the Labyrinth?(y/n)"<<endl;
    getline(cin,response);
    if(response == "n"){
        cout<<"Smart choice"<<endl;
    }
    else if(response == "y"){
        signPost();
        while(running){ //while the game is running
            if(one->bag->hasAllGems()){ //checks if the player has all gems
                cout<<"The dragon has appeared. Defeat him to escape!"<<endl;
                node*x = maze.returnStartingPos();
                x->monsterOn = true;
                x->monster = "Dragon";
            }
            cout<<"You are on position: "<<one->position->point<<endl;
            cout<<one->position->available_moves<<endl;
            cout<<"Given your available moves, would you like to:"<<endl<<"(w) Go forward? "<<endl<<"(s) Go backward?"<<endl<<"(a) Go left?"<<endl<<"(d) Go right?"<<endl<<"(1) Place marker?"<<endl<<"(2) Look at inventory?"<<endl<<"(p) Give up?"<<endl;
            cin.clear();
            cin>>response;
            if(response == "w"){
                one->moveForward();
            }
            if(response =="s"){
                one->moveBackward();
            }
            if(response =="a"){
                one->moveLeft();
            }
            if(response =="d"){
                one->moveRight();
            }
            if(response =="1"){
                one->placeMarker();
            }
            if(response =="2"){
                one->printInventory();
            }
            if(response == "p"){
                running = false;
            }
            if(one->position == maze.returnStartingPos() && one->position->monsterOn==true){ //checks to see if you're on the start point and the dragon is turned on
                if(one->weapon == "Butter Knife"){ //if you have the butter knife
                    cout<<"Are you ready to face the dra";
                    int x=0;
                    while(x<3){
                        cout<<".";
                        x++;
                    }
                    cout<<"He came at you and you instinctively pulled out your ''Butter Knife'' and he instantly died! Congratulations! You escaped the maze!"<<endl;
                    running = false;
                }
                else{// if you don't have the butter knife
                    cout<<"Are you ready to face the dragon?(y/n)"<<endl;
                    string x;
                    cin.ignore();
                    getline(cin,x);
                    if(x == "y"){
                        cout<<"You got eaten... Sad day..."<<endl;
                        running = false;
                    }
                    if(x=="n"){
                        cout<<"That's probably for the best. You should probably find a weapon."<<endl;
                        one->moveForward();
                    }
                }
            }

        }

    }
    else{
        cout<<"Maybe try a reading class first"<<endl;
    }

}


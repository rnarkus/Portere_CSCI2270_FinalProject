#ifndef LABRYNTH_H
#define LABRYNTH_H
#include <string>
struct node{
    std::string available_moves = "Available Directions:";
    std::string point;
    std::string markerTxt;
    bool marker = false;
    bool visited = false;
    node *next;
    node *prev;
    node *left;
    node *right;
    std::string treasure;
    std::string monster;
    bool monsterOn = false;

    node(){};
};

struct pouch{

    int gemCount = 0;
    std:: string gems[3];
    int markerCount;
    pouch(){};
    void printPouch();
    bool hasAllGems();

};


struct player{
    std::string name;
    node* position;
    pouch* bag = new pouch();
    std::string weapon;
    player(){};
    void addGem(std::string, pouch* bag);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void placeMarker();
    void printInventory();
    player(std::string in_name, node* in_position){
        name = in_name;
        position = in_position;
        position->visited = true;
    }

};


class Labyrinth
{
    public:
        void buildLabyrinth();
        node* returnStartingPos();
    private:
        node* start;
};

#endif // HASHTABLE_H


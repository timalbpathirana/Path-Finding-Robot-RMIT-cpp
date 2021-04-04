#include "Node.h"
#include "Types.h"
#include <string.h>
#include <iostream>
int distancee = 0;

// this class is to replresenbt the position of the robot, position (col,row,distance_travelled) 

/* 
TheNodeclass represents a position of the robot. It is a tuple(col,row,distance_travelled), which is thex-ylocation of the robot, and the distance that the algorithm took to reach that position from the robot’sstarting position. It contains getters for this information and setter fordistance_travelled.


*/


Node::Node(int row, int col, int dist_traveled)
{
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
}

Node::Node(){}

Node::~Node(){}   

int Node::getRow(){
    return row;
}

int Node::getCol(){
    return col;
 }

int Node::getDistanceTraveled(){
    
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    this->dist_traveled = dist_traveled;
}

//getter for estimated dist to goal - need to return -> Manhatten distance + distance traveled
int Node::getEstimatedDist2Goal(Node* goal){

    int manHDColValue;
    int manHDRowValue;
    int ManhattenDistance;
    

    manHDColValue = this->getCol() - goal->getCol();
    if(manHDColValue < 0){
        manHDColValue = manHDColValue * -1;
    }
    manHDRowValue = this->getRow() - goal->getRow();
    if(manHDRowValue < 0){
        manHDRowValue = manHDRowValue * -1;
    }
    
    ManhattenDistance = manHDColValue + manHDRowValue; 

    int tot = this->getDistanceTraveled() + ManhattenDistance;
    return (tot) ;
}
                          
#include "PathSolver.h"
#include <iostream>

    
int startRowCount = 0;
int startColCount = 0;
int goalRowCount = 0;
int goalColCount = 0;

//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
    // TODO
   //NodeList* nodeList = new NodeList();
    
}


PathSolver::~PathSolver(){
    // TODO
}

void PathSolver::forwardSearch(Env env){
    // TODO 
    
    char* arrayStartPtr = &(env[0][0]);
    char* arrayGoalPtr = &(env[0][0]);

// Checking the start node and get the coordinates    
    for (int row = 0; row < ENV_DIM; row++)
        {
            for (int col = 0; col < ENV_DIM; col++)
            {
                if (env[row][col] == SYMBOL_START)
                {
                   arrayStartPtr = &(env[row][col]);
                   startColCount = col;
                   startRowCount = row;
                }  
            }   
        }


//  Checking the goal node and get the coordinates
    for (int row = 0; row < ENV_DIM; row++)
        {
            for (int col = 0; col < ENV_DIM; col++)
            {
                if (env[row][col] == SYMBOL_GOAL)
                {
                   arrayGoalPtr = &(env[row][col]);
                   goalColCount = col;
                   goalRowCount = row;
                }   
            }   
        }
    
    // Printing the start node and the goal node
    std::cout << "This is the start pointer:" << *arrayStartPtr << "and the coordinates are: " << startRowCount << ":" << startColCount <<'\n';

    std::cout << "This is the Goal pointer:" << *arrayGoalPtr << "and the coordinates are: " << goalRowCount << ":" << goalColCount <<'\n';

    // std::cout << "Checking the right node:" << *(startArrayPtr + 1) << '\n';

    // std::cout << "Checking the down node:" << *(startArrayPtr + ENV_DIM) << '\n';

    // Making Nodes and put those start and goal as nodes
    Node* startNode  = new Node(startRowCount,startColCount, 0);
    Node goalNode(goalRowCount,goalColCount, INFINITY);

    // make a pointer to the memory address of startNode
    //Node* startNodePtr = &startNode; 
    //Node* goalNodePtr = &goalNode;

    // Making Open list and Closed List using NodeList class
    NodeList openList;
    openList.setLength(0);
    NodeList closeist;

    // Adding start node to the Open node list to begin the search
    openList.addElement(startNode);
    
    // Searching for path from current node

    //Searching for right
    if(*(arrayStartPtr + 1) != SYMBOL_WALL ) {
        openList.addElement(startNode + 1);

    // Searching for left
    if (*(arrayStartPtr - 1) != SYMBOL_WALL){
        openList.addElement(startNode - 1);
    }

    // Searching for bottom
    if(*(arrayStartPtr + ENV_DIM) != SYMBOL_WALL) {
        openList.addElement(startNode + ENV_DIM);
    }

    // Searching for top
    if(*(arrayStartPtr - ENV_DIM) != SYMBOL_WALL) {
        openList.addElement(startNode - ENV_DIM);
    }
    

    }
    

    std::cout << "Nodes inside the List: " << openList.getLength() << '\n';
} 

void findStartNode (Env env){
    char* arrayStartPtr = &(env[0][0]);
        for (int row = 0; row < ENV_DIM; row++)
        {
            for (int col = 0; col < ENV_DIM; col++)
            {
                if (env[row][col] == SYMBOL_START)
                {
                   arrayStartPtr = &(env[row][col]);
                }
                
            }
            
        }
    std::cout << "This is the start pointer:" << *arrayStartPtr << '\n';
        
}


// Node* findGoalNode (Env env){

// }



NodeList* PathSolver::getNodesExplored(){
    //TODO
    return nullptr;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    return nullptr;
}


//-----------------------------
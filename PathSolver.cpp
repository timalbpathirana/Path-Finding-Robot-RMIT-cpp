#include "PathSolver.h"
#include <iostream>

    
int currentRowCount = 0;
int currentColCount = 0;
int goalRowCount = 0;
int goalColCount = 0;
 // Making Open list and Closed List using NodeList class
NodeList openList;
NodeList closeList;
char* nextPtr = nullptr;


//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
    // TODO   
}


PathSolver::~PathSolver(){
    // TODO
}



void PathSolver::forwardSearch(Env env){
    // TODO 
    
    
    char* arrayStartPtr = &(env[0][0]);
    char* arrayGoalPtr = &(env[0][0]);

    nextPtr  = getNodeCordinates(env, SYMBOL_START ,arrayStartPtr);
    arrayGoalPtr =getNodeCordinates(env, SYMBOL_GOAL,arrayGoalPtr);

    //std::cout << "nextPtr Pointer value: " << *nextPtr <<'\n';
    


    // Making Nodes and put those start and goal as nodes
    Node* startNode  = new Node(currentRowCount,currentColCount, 0);
    Node* goalNode  = new Node(goalRowCount,goalColCount, 0);
    openList.addElement(startNode);
    //closeList.addElement(startNode);
    

//---------------------------------------------------------
    // moving the robot by getting the closest node from the openList 
   
   //Searching for available path nodes
    
    


    // Getting the node pointer with smallest path cost
    
    


    // searchNodes(&nextPtr);
    // std::cout << "searchNode works AGAIN"<< '\n';

    // getFastPath(goalNode);
    // std::cout << "GetFastWorks AGAIN"<< '\n';
    // std::cout << "OPENLIST: " << openList.getLength() << '\n';
    // std::cout << "CLOSELIST: " << closeList.getLength() << '\n';
        
     
    // do {
    //     searchNodes(nextPtr);
    //     getFastestPath(goalNode);
        
    
    // std::cout << "OPENLIST: " << openList.getLength() << '\n';

    // }
    // while (*nextPtr != 'G');

    
     searchNodes(nextPtr);
     getFastestPath(goalNode);
     std::cout << "No of Nodes in OPENLIST: " << openList.getLength() << '\n';
     std::cout << "No of Nodes in CLOSELIST: " << closeList.getLength() << '\n';
     std::cout << '\n';
     std::cout << "NEXT ROUND" << '\n';
     
    searchNodes(nextPtr);  
    getFastestPath(goalNode); 
    std::cout << "OPENLIST: " << openList.getLength() << '\n';
     std::cout << "CLOSELIST: " << closeList.getLength() << '\n';
     std::cout << "NEXT ROUND" << '\n';
     std::cout << '\n';
    searchNodes(nextPtr);  
    getFastestPath(goalNode); 
    std::cout << "OPENLIST: " << openList.getLength() << '\n';
     std::cout << "CLOSELIST: " << closeList.getLength() << '\n';
     std::cout << "NEXT ROUND" << '\n';
     std::cout << '\n';
    searchNodes(nextPtr);  
    getFastestPath(goalNode); 

    


} 

NodeList* PathSolver::getNodesExplored(){
    //TODO
    return nullptr;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    return nullptr;
}



void PathSolver::getFastestPath(Node* goalNode){
    int array[openList.getLength()];
    int MIN;
    int outPutNodeIndex =0;
    
        // Making an array with distacne to the goal
        for (int i = 0; i < openList.getLength(); i++)
        {
            array[i] = openList.getNode(i)->getEstimatedDist2Goal(goalNode);
        }
        //std::cout << "first loop works"<< '\n';

        // getting the node with min distance to the goal
        for (int i = 0; i < openList.getLength(); i++)
        {
            if (array[i] < MIN)
            {
                MIN = array[i];
            }
            
        }
        //std::cout << "second loop works"<< '\n';
        for (int i = 0; i < openList.getLength(); i++)
        {
            if (openList.getNode(i)->getEstimatedDist2Goal(goalNode) == MIN){
            outPutNodeIndex = i;

            }
        }
        //std::cout << "third loop works"<< '\n';

    Node* minPtr = openList.getNode(outPutNodeIndex); 
    
    closeList.addElement(minPtr);
    //std::cout << "print works"<< '\n';
    
    
        
        
}

void PathSolver::searchNodes (char* SPtr){


    
    

     //Searching for right
     if(*(SPtr + 1) != SYMBOL_WALL ) {

        Node* nextNode  = new Node(currentRowCount,currentColCount + 1, 1);
        
        NodeList* nodeLstPtr = &closeList;
        for (int i = 0; i < closeList.getLength(); i++)
        {
           if (nextNode != nodeLstPtr->getNode(i))
           {
               openList.addElement(nextNode);
           }
           
        }
        
        nextPtr = (SPtr + 1);
        std::cout << "Go Right Triggered" << "\n";
        //std::cout << "After Search value: " << *nextPtr <<'\n';
        
       
    }

    // Searching for left
    if (*(SPtr - 1) != SYMBOL_WALL){
        Node* nextNode  = new Node(currentRowCount,currentColCount - 1, 1);
        NodeList* nodeLstPtr = &closeList;
        for (int i = 0; i < closeList.getLength(); i++)
        {
           if (nextNode != nodeLstPtr->getNode(i))
           {
               openList.addElement(nextNode);
           }
           
        }
        nextPtr = (SPtr - 1);
        std::cout << "Go Left Triggered" << "\n";
        
        
       
    }

    // Searching for bottom
    if(*(SPtr + ENV_DIM) != SYMBOL_WALL) {
        Node* nextNode  = new Node(currentRowCount + 1,currentColCount, 1);
        NodeList* nodeLstPtr = &closeList;
        for (int i = 0; i < closeList.getLength(); i++)
        {
           if (nextNode != nodeLstPtr->getNode(i))
           {
               openList.addElement(nextNode);
           }
           
        }
        nextPtr = (SPtr + ENV_DIM);
        std::cout << "down triggered" << "\n";
        
        
    }

    // Searching for top
    if(*(SPtr - ENV_DIM) != SYMBOL_WALL) {
        Node* nextNode  = new Node(currentRowCount -1 ,currentColCount, 1);
        NodeList* nodeLstPtr = &closeList;
        for (int i = 0; i < closeList.getLength(); i++)
        {
           if (nextNode != nodeLstPtr->getNode(i))
           {
               openList.addElement(nextNode);
           }
           
        }
        nextPtr = (SPtr - ENV_DIM);
        std::cout << "up triggered" << "\n";
        
        
    }
    
    
}
 
 char* PathSolver::getNodeCordinates(Env env, char name , char* chPtr){
    
// Checking the start node and get the coordinates    
    for (int row = 0; row < ENV_DIM; row++)
        {
            for (int col = 0; col < ENV_DIM; col++)
            {
                if (env[row][col] == name)
                {
                   chPtr = &(env[row][col]);
                   currentColCount = col;
                   currentRowCount = row;
                   
                }  
            }   
        }
    // std::cout << "Pointer:" << *chPtr << "  and the coordinates are: " << currentRowCount << ":" << currentColCount <<'\n';
    return chPtr;
 }
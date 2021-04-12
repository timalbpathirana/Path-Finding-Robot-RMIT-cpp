#include "PathSolver.h"
#include <iostream>


// Creating all the global varibles and pointers and initialising them
int minNodeIndex =0 ;
int distanceTravelled = 0;
Node* startPtr = nullptr;
Node* goalPtr = nullptr;
Node* currentP = nullptr;

// Making node objects to create openlist array and closedlist array
NodeList openListArr;
NodeList closedListArr;

//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
    // TODO   
}


PathSolver::~PathSolver(){
    // TODO
}


// Starting the forward search and add the neighbour free nodes to open list.

void PathSolver::forwardSearch(Env env){
    // Getting start node 
    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            if (env[row][col] == SYMBOL_START)
            {
                Node* sNodePtr = new Node(row, col, 0);
                startPtr = sNodePtr;
        
            }
         }
    }
    // Getting goal pointer 
    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            if (env[row][col] == SYMBOL_GOAL)
            {
                Node* gNodePtr = new Node(row, col, 0);
                goalPtr = gNodePtr;
                
            }
        }
    }
//-------------------------------------------------------------------------------------

//g++ -Wall -Werror -std=c++14 -O -o assign1 Node.cpp NodeList.cpp PathSolver.cpp main.cpp

// Adding SYMBOL_START to the openlist to begin the search
openListArr.addElement(startPtr);

// Start the algorithem for searching nodes
 do {    
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    
    } while (env[currentP->getRow()][currentP->getCol()] != env[goalPtr->getRow()][goalPtr->getCol()]);

for (int i = 0; i < closedListArr.getLength(); i++){
    std::cout << "Env[Row][Col]: " << closedListArr.getNode(i)->getRow() << ":" << closedListArr.getNode(i)->getCol() << '\n';
    }
}
//-------------------------------------------------------------------------------------

// Selecting the simple p
void PathSolver::selectP(){
int distance  = 100;

//Making the distance to a larger number before starting the filtering
   for (int i = 0; i < openListArr.getLength(); i++)
   {
       if (openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr) < distance && isNotOnClosedList(openListArr.getNode(i)))
       
       {
           distance = openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr);
           std::cout << "Distance: " << distance << '\n';
           minNodeIndex = i;

       }
       
   }

    currentP = openListArr.getNode(minNodeIndex);
    std::cout << "p Node Col:Row "<< currentP->getRow() << ':'<< currentP->getCol() << '\n';
}

//-------------------------------------------------------------------------------------


bool PathSolver::isNotOnClosedList(Node* nodePtr){
    for (int i = 0; i < closedListArr.getLength(); i++)
    {
        if(nodePtr->getRow() == closedListArr.getNode(i)->getRow() && nodePtr->getCol() == closedListArr.getNode(i)->getCol()){
            return false;
        }
    }
    return true;
    
}

//-------------------------------------------------------------------------------------

// Searching neighbour cordinates for SYMBOL_EMPTY OR SYMBOL_GOAL.
void PathSolver::searchNodesBeforeAdd(Env env, Node* pPtr){

Node* rightNodePtr = nullptr;
Node* leftNodePtr = nullptr;
Node* upNodePtr = nullptr;
Node* downNodePtr = nullptr;

// Check for the Right node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getRow()][pPtr->getCol()+ 1] == SYMBOL_EMPTY || env[pPtr->getRow()][pPtr->getCol()+ 1] == SYMBOL_GOAL){

    Node rightNode(pPtr->getRow(),pPtr->getCol()+ 1,distanceTravelled + 1);
    rightNodePtr = &rightNode;
        if(isNotOnClosedList(rightNodePtr)){
        openListArr.addElement(rightNodePtr);
        std::cout << "Moving Right" << '\n';
        std::cout << '\n';
    }
    
}

// Check for the Left node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getRow()][pPtr->getCol()- 1] == SYMBOL_EMPTY || env[pPtr->getRow()][pPtr->getCol()- 1] == SYMBOL_GOAL)  {
    
    Node leftNode(pPtr->getRow(),pPtr->getCol() -1, distanceTravelled + 1);
    leftNodePtr = &leftNode;

    if(isNotOnClosedList(leftNodePtr)){
        openListArr.addElement(leftNodePtr);
        std::cout << "Moving Left" << '\n';
        std::cout << '\n';
    }  
}

// Check for the Down node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getRow() + 1][pPtr->getCol()] == SYMBOL_EMPTY || env[pPtr->getRow() + 1][pPtr->getCol()] == SYMBOL_GOAL)  {
    
    Node downNode(pPtr->getRow() + 1,pPtr->getCol(), distanceTravelled + 1);
    downNodePtr = &downNode;

    if(isNotOnClosedList(downNodePtr)){
        openListArr.addElement(downNodePtr);
        std::cout << "Moving Down" << '\n';
        std::cout << '\n';
    }  
}

// Check for the Up node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getRow() - 1][pPtr->getCol()] == SYMBOL_EMPTY || env[pPtr->getRow() - 1][pPtr->getCol()] == SYMBOL_GOAL)  {
    
    Node upNode(pPtr->getRow() - 1,pPtr->getCol(), distanceTravelled + 1);
    upNodePtr = &upNode;

    if(isNotOnClosedList(upNodePtr)){
        openListArr.addElement(upNodePtr);
        std::cout << "Moving Down" << '\n';
        std::cout << '\n';
    }  
}
// Distance travelled must be +1 from the last node. 
distanceTravelled++;
} 
    

NodeList* PathSolver::getNodesExplored(){
    return &closedListArr;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    
    return nullptr;
}


 
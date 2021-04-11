#include "PathSolver.h"
#include <iostream>
#include <algorithm>
#include <iterator>


// Creating all the global varibles and pointers and initialising them
bool isNextNodeInOpenList;
int minNodeIndex =0 ;
int distanceTravelled = 0;
NodeList openListArr;
NodeList closedListArr;

Node* startPtr = nullptr;
Node* goalPtr = nullptr;
Node* currentP = nullptr;


//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
    // TODO   
}


PathSolver::~PathSolver(){
    // TODO
}


// Starting the forward search and add the neighbour free nodes to open list.

void PathSolver::forwardSearch(Env env){
    // TODO 

//-------------------------------------------------------------------------------------
    // Seach the Goal cordinate of the env and pointing the goalPtr to the G cordinates
    
    // Getting start node 
    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            if (env[col][row] == SYMBOL_START)
            {
                Node* startNode = new Node(row, col, 0);
                // direct the startPtr to startNode to access from other functions
                startPtr = startNode;
        
            }
         }
    }
    // Getting goal pointer 
    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            if (env[col][row] == SYMBOL_GOAL)
            {
                Node* goalNode = new Node(row, col, 0);
                // direct the startPtr to startNode to access from other functions
                goalPtr = goalNode;
                
            }
        }
    }
//-------------------------------------------------------------------------------------

//Notes for myself
/* When we use new keyword, it will not destroy by the program after we done with the program, its dev responsility to delete those after - https://stackoverflow.com/questions/15310846/creating-a-class-object-in-c/40169699
*/


// Adding SYMBOL_START to the openlist to begin the search
openListArr.addElement(startPtr);

// Start the algorithem for searching nodes
do
{
       
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    
} while (env[currentP->getCol()][currentP->getRow()] != env[goalPtr->getCol()][goalPtr->getRow()]);

}

//-------------------------------------------------------------------------------------


// Selecting the simple p
void PathSolver::selectP(){
int distance  = INFINITY;


    //Making the distance to a larger number before starting the filtering
    /*
    1. Select the node with lowest distance and NOT in closed list

    */
   for (int i = 0; i < openListArr.getLength(); i++)
   {
       if (openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr) < distance && isNotOnClosedList(openListArr.getNode(i)))
       {
           distance = openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr);
           minNodeIndex = i;

       }
       
   }

    currentP = openListArr.getNode(minNodeIndex);
    std::cout << "p Node Col:Row "<< currentP->getCol() << ':'<< currentP->getRow() << '\n';
    std::cout << '\n';
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

//This method searches the nodes which are coming from search and only add to the openlist if they are not already inside the closedlist to avoid openlist overflow.
bool PathSolver::searchCloseListByChar(Env env, char* cPtr){

    bool openx= false; 
    for (int i = 0; i < closedListArr.getLength(); i++)
    {
        if (&(env[closedListArr.getNode(i)->getCol()][closedListArr.getNode(i)->getRow()]) == cPtr)
        {
           openx= true;
        }
        
    }
    return openx;
    
}

//-------------------------------------------------------------------------------------

// Searching neighbour cordinates for SYMBOL_EMPTY OR SYMBOL_GOAL.
void PathSolver::searchNodesBeforeAdd(Env env, Node* pPtr){

// Check for the Right node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol()][pPtr->getRow()+ 1] == SYMBOL_EMPTY || env[pPtr->getCol()][pPtr->getRow()+ 1] == SYMBOL_GOAL){

    Node* rightNode = new Node(pPtr->getRow()+ 1,pPtr->getCol(),distanceTravelled + 1);
    if(searchCloseListByChar(env, &(env[pPtr->getCol()][pPtr->getRow()+ 1])) == false){
        openListArr.addElement(rightNode);
        std::cout << "Going Right" << '\n';
    }
    // Freeing up the space for the new node if that node is already on the openlist
    else{
        delete rightNode;
    }
}

// Check for the Left node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol()][pPtr->getRow()- 1] == SYMBOL_EMPTY || env[pPtr->getCol()][pPtr->getRow()- 1] == SYMBOL_GOAL)  {
    
    Node* leftNode = new Node(pPtr->getRow()- 1,pPtr->getCol(), distanceTravelled + 1);
    if(searchCloseListByChar(env, &(env[pPtr->getCol()][pPtr->getRow()- 1])) == false){
        openListArr.addElement(leftNode);
        std::cout << "Going Left" << '\n';
    }
    // Freeing up the space for the new node if that node is already on the openlist
    else{
        delete leftNode;
    }    
}

// Check for the Down node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() + 1][pPtr->getRow()] == SYMBOL_EMPTY || env[pPtr->getCol() + 1][pPtr->getRow()] == SYMBOL_GOAL)  {
    
    Node* downNode = new Node(pPtr->getRow(),pPtr->getCol() + 1, distanceTravelled + 1);
    if(searchCloseListByChar(env,&(env[pPtr->getCol() + 1][pPtr->getRow()])) == false){
        openListArr.addElement(downNode);
        std::cout << "Going Down" << '\n';
    }
    else{
        delete downNode;
    }    
}

// Check for the Up node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() - 1][pPtr->getRow()] == SYMBOL_EMPTY || env[pPtr->getCol() - 1][pPtr->getRow()] == SYMBOL_GOAL)  {
    
    Node* upNode = new Node(pPtr->getRow(),pPtr->getCol() - 1, distanceTravelled + 1);

    if(searchCloseListByChar(env, &(env[pPtr->getCol() - 1][pPtr->getRow()])) == false){
        openListArr.addElement(upNode);
        std::cout << "Going Up" << '\n';
    }

    else{
        delete upNode;
    }    
}
// Distance travelled must be +1 from the last node. 
distanceTravelled++;
} 
    

NodeList* PathSolver::getNodesExplored(){
    //TODO
    return nullptr;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    return nullptr;
}


 
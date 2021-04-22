#include "PathSolver.h"
#include <iostream>

//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
}


PathSolver::~PathSolver(){
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

// Adding SYMBOL_START to the openlist to begin the search
openListArr->addElement(startPtr);

// Start the algorithem for searching nodes
 do {    
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr->addElement(currentP);
    
    } while (env[currentP->getRow()][currentP->getCol()] != env[goalPtr->getRow()][goalPtr->getCol()]);


}
//-------------------------------------------------------------------------------------

// Selecting the simple p
void PathSolver::selectP(){
int distance  = 100;

//Making the distance to a larger number before starting the filtering
   for (int i = 0; i < openListArr->getLength(); i++)
   {
       // looping through the openlist to find the node with minimum estimated distance and then grabbing the index for that node. 
       if (openListArr->getNode(i)->getEstimatedDist2Goal(goalPtr) <= distance && isNotOnClosedList(openListArr->getNode(i)))
       
       {
           distance = openListArr->getNode(i)->getEstimatedDist2Goal(goalPtr);
           minNodeIndex = i;

       }
       
   }
// Selecting the current simple p 
    currentP = openListArr->getNode(minNodeIndex);
}





/* Checking if the neighbour nodes are inside the closed list before add to the openlist.
Return true if that node is NOT inside the closedlist */
bool PathSolver::isNotOnClosedList(Node* nodePtr){
    for (int i = 0; i < closedListArr->getLength(); i++)
    {
        if(nodePtr->getRow() == closedListArr->getNode(i)->getRow() && nodePtr->getCol() == closedListArr->getNode(i)->getCol()){
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
bool isNodeAdded = false;

// Check for the Right node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getRow()][pPtr->getCol()+ 1] == SYMBOL_EMPTY || env[pPtr->getRow()][pPtr->getCol()+ 1] == SYMBOL_GOAL){

    Node rightNode(pPtr->getRow(),pPtr->getCol()+ 1,distanceTravelled + 1);
    rightNodePtr = &rightNode;
        if(isNotOnClosedList(rightNodePtr)){
        openListArr->addElement(rightNodePtr);
        isNodeAdded = true;
        //std::cout << "Moving Right" << '\n';
       // std::cout << '\n';
    }
    
}


// Check for the Left node and also check if its available in the open list and If not, add to open list 
    if(env[pPtr->getRow()][pPtr->getCol()- 1] == SYMBOL_EMPTY || env[pPtr->getRow()][pPtr->getCol()- 1] == SYMBOL_GOAL)  {
    
        Node leftNode(pPtr->getRow(),pPtr->getCol() -1, distanceTravelled + 1);
        leftNodePtr = &leftNode;
        if(isNotOnClosedList(leftNodePtr)){
            openListArr->addElement(leftNodePtr);
            isNodeAdded = true;
            //std::cout << "Moving Left" << '\n';
            // std::cout << '\n';
        }  
    }

// Check for the Down node and also check if its available in the open list and If not, add to open list 
    if(env[pPtr->getRow() + 1][pPtr->getCol()] == SYMBOL_EMPTY || env[pPtr->getRow() + 1][pPtr->getCol()] == SYMBOL_GOAL)  {
    
        Node downNode(pPtr->getRow() + 1,pPtr->getCol(), distanceTravelled + 1);
        downNodePtr = &downNode;
        if(isNotOnClosedList(downNodePtr)){
            openListArr->addElement(downNodePtr);
            isNodeAdded = true;
            //std::cout << "Moving Down" << '\n';
            //std::cout << '\n';
        }  
    }

// Check for the Up node and also check if its available in the open list and If not, add to open list 
    if(env[pPtr->getRow() - 1][pPtr->getCol()] == SYMBOL_EMPTY || env[pPtr->getRow() - 1][pPtr->getCol()] == SYMBOL_GOAL)  {
    
        Node upNode(pPtr->getRow() - 1,pPtr->getCol(), distanceTravelled + 1);
        upNodePtr = &upNode;

        if(isNotOnClosedList(upNodePtr)){
            openListArr->addElement(upNodePtr);
            isNodeAdded = true;
            //std::cout << "Moving Down" << '\n';
            //std::cout << '\n';
        }  
    }
// Distance travelled must be +1 from the last node. 
    if (isNodeAdded == true){
        distanceTravelled++;
    }

} 


    

NodeList* PathSolver::getNodesExplored(){
    
    // Making a deep copy of the closedlist and create a new list on heap.
    NodeList* closedListDeepCopy = new NodeList(*closedListArr);
    closedListDeepCopyPtr = closedListDeepCopy;
    return closedListDeepCopy;
}



NodeList* PathSolver::getPath(Env env){
     
    //grabbing the number of elements on the copied array for easy use
    int numbOfElements = closedListDeepCopyPtr->getLength() - 1;
    //Making a new backArray to reverse the node list for M3
    NodeList* backArray = new NodeList();
   
    // adding the goal node as the first node
    backArray->addElement(closedListDeepCopyPtr->getNode(numbOfElements));
   
   // Making a pointer to the goal node
    Node* gNodePtr = closedListDeepCopyPtr->getNode(numbOfElements);
    // Declaring getPath method variables
    Node* previousNodePtr = gNodePtr;
    int previousNodeIndex = numbOfElements;

for (int i = 0; i < numbOfElements; i++)
{
   
// checking the right node to see if that is empty or start node
    if(env[previousNodePtr->getRow()][previousNodePtr->getCol() + 1] == SYMBOL_EMPTY || env[previousNodePtr->getRow()][previousNodePtr->getCol() + 1] == SYMBOL_START) {
        // if so, check if that node is already inside the explored list and we only choose that if its inside the explored array.
        for (int i = 0; i < closedListDeepCopyPtr->getLength(); i++)
        {
            if(env[previousNodePtr->getRow()][previousNodePtr->getCol() + 1] == env[closedListDeepCopyPtr->getNode(i)->getRow()][closedListDeepCopyPtr->getNode(i)->getCol()]){
                // Check if that node's distance travelled 1 less than the previous node's distance travelled.If so, thats the next node to go.
                if(closedListDeepCopyPtr->getNode(i)->getDistanceTraveled() == closedListDeepCopyPtr->getNode(previousNodeIndex)->getDistanceTraveled() - 1) {
                    backArray->addElement(closedListDeepCopyPtr->getNode(i));
                    previousNodeIndex = i;
                    //std::cout << "right triggered" << '\n';
                    
                    
                    

                }
            }
        }
        

    }
// checking the left node 
    if(env[previousNodePtr->getRow()][previousNodePtr->getCol() - 1] == SYMBOL_EMPTY || env[previousNodePtr->getRow()][previousNodePtr->getCol() - 1] == SYMBOL_START ) {
        for (int i = 0; i < closedListDeepCopyPtr->getLength(); i++)
        {
            if(env[previousNodePtr->getRow()][previousNodePtr->getCol() - 1] == env[closedListDeepCopyPtr->getNode(i)->getRow()][closedListDeepCopyPtr->getNode(i)->getCol()]){
                if(closedListDeepCopyPtr->getNode(i)->getDistanceTraveled() == closedListDeepCopyPtr->getNode(previousNodeIndex)->getDistanceTraveled() - 1) {
                    backArray->addElement(closedListDeepCopyPtr->getNode(i));
                    previousNodeIndex = i;
                    //std::cout << "l triggered" << '\n';
                   
                }
            }
        }
        

    }
// checking the down node
    if(env[previousNodePtr->getRow() + 1][previousNodePtr->getCol()] == SYMBOL_EMPTY || env[previousNodePtr->getRow() + 1][previousNodePtr->getCol()] == SYMBOL_START) {
        for (int i = 0; i < closedListDeepCopyPtr->getLength(); i++)
        {
            if(env[previousNodePtr->getRow() + 1][previousNodePtr->getCol()] == env[closedListDeepCopyPtr->getNode(i)->getRow()][closedListDeepCopyPtr->getNode(i)->getCol()]){
                if(closedListDeepCopyPtr->getNode(i)->getDistanceTraveled() == closedListDeepCopyPtr->getNode(previousNodeIndex)->getDistanceTraveled() - 1) {
                    
                    backArray->addElement(closedListDeepCopyPtr->getNode(i));
                    previousNodeIndex = i;
                    //std::cout << "down triggered" << '\n';
                    
                }
            }
        }
    }

// checking the up node
    if(env[previousNodePtr->getRow() - 1][previousNodePtr->getCol()] == SYMBOL_EMPTY || env[previousNodePtr->getRow() - 1][previousNodePtr->getCol()] == SYMBOL_START) {
        for (int i = 0; i < closedListDeepCopyPtr->getLength(); i++)
        {
            if(env[previousNodePtr->getRow() - 1][previousNodePtr->getCol()] == env[closedListDeepCopyPtr->getNode(i)->getRow()][closedListDeepCopyPtr->getNode(i)->getCol()]){
                if(closedListDeepCopyPtr->getNode(i)->getDistanceTraveled() == closedListDeepCopyPtr->getNode(previousNodeIndex)->getDistanceTraveled() - 1) {
                    backArray->addElement(closedListDeepCopyPtr->getNode(i));
                    previousNodeIndex = i;
                    //std::cout << "up triggered" << '\n';
                   
                    
                    
                }
            }
        }
    }

// Selecting the next node 
previousNodePtr = closedListDeepCopyPtr->getNode(previousNodeIndex);

}





//making a new arraylist to reverse the backarray list
NodeList* newList = new NodeList();

// Populating the newList
for (int i = 1; i < backArray->getLength() + 1; i++)
{
    newList->addElement(backArray->getNode(backArray->getLength() - i));
}
return newList;
}





/* 

Compiling codes - 
g++ -Wall -Werror -std=c++14 -O -o assign1 Node.cpp NodeList.cpp PathSolver.cpp main.cpp
./assign1

*/

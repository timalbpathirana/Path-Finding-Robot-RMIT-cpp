#include "PathSolver.h"
#include <iostream>
#include <vector>

    
Node* startPtr = nullptr;
Node* goalPtr = nullptr;
Node* currentP = nullptr;


bool isNextNodeInOpenList;
int minNodeIndex =0 ;
int distanceTravelled = 0;
NodeList openListArr;
NodeList closedListArr;






//that executes the forward search and backtracking algorithms.

PathSolver::PathSolver(){
    // TODO   
}


PathSolver::~PathSolver(){
    // TODO
}



void PathSolver::forwardSearch(Env env){
    // TODO 
    
    
    

//---------------------------------------------------------
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


    
    
//---------------------------------------------------------

// Creating a Open list and add S to the list.

/* When we use new keyword, it will not destroy by the program after we done with the program, its dev responsility to delete those after - https://stackoverflow.com/questions/15310846/creating-a-class-object-in-c/40169699
*/

openListArr.setLength(0);
closedListArr.setLength(0);


// Adding s to the openlist
openListArr.addElement(startPtr);

do
{
        std::cout << '\n';
        std::cout << "New Round" << '\n';
        selectP();
        searchNodesBeforeAdd(env, currentP);
        closedListArr.addElement(currentP);
    
        std::cout << "OpenList Count: " << openListArr.getArraySize() << '\n';
        std::cout << "ClosedList Count: " << closedListArr.getArraySize() << '\n';

} while (env[currentP->getCol()][currentP->getRow()] != env[goalPtr->getCol()][goalPtr->getRow()]);

    // for (int i = 0; i < 20; i++)
    // {
    //     std::cout << '\n';
    //     std::cout << "ROUND:"<< i << '\n';
    //     std::cout << '\n';
    //     selectP();
        
    //     searchNodesBeforeAdd(env, currentP);
    //     closedListArr.addElement(currentP);
    
    //     std::cout << "OpenList Count: " << openListArr.getArraySize() << '\n';
    //     std::cout << "ClosedList Count: " << closedListArr.getArraySize() << '\n';
    // }
    
    

}


// Check for the Right node and also check if its available in the open list and If not, add to open list 



// Selecting the simple p

void PathSolver::selectP(){


int rounds = openListArr.getArraySize();

for (int y = 0; y < rounds; y++){
    int distance  = 100;
    
        for (int i = 0; i < openListArr.getArraySize(); i++){
            
            if (openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr) < distance) {
                distance = openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr);
                minNodeIndex = i;
                
            }
        }
// Cannot put in the same loop as above for loop needs to finish to the final value for minNodeIndex
        for (int i = 0; i < closedListArr.getArraySize(); i++){
            if ((openListArr.getNode(minNodeIndex)->getCol() == closedListArr.getNode(i)->getCol()) && (openListArr.getNode(minNodeIndex)->getRow() == closedListArr.getNode(i)->getRow())){
               //openListArr.removeElement(minNodeIndex);
               minNodeIndex = i + 1;
            }   
    
        }
    }

    currentP = openListArr.getNode(minNodeIndex);

    std::cout << "p Node Col:Row "<< currentP->getCol() << ':'<< currentP->getRow() << '\n';
    //std::cout << "Returning P Node pointer: " << pNode <<'\n';
}

// bool PathSolver::isNodeOnClosedList(Node* closePtr){

//     bool closeX= true; 

    
//     for (int i = 0; i < closedListArr.getArraySize(); i++)
//     {
//         if ( closedListArr.getNode(i) == closePtr)
//         {
//            closeX = false;
//            std::cout << "FALSE TRIGGERED" << '\n';

//         }
        
//     }
//     return closeX;
    
// }


bool PathSolver::isNodeOnOpenList(Env env, char* cPtr){

    bool openx= false; 
    for (int i = 0; i < openListArr.getArraySize(); i++)
    {
        if (&(env[openListArr.getNode(i)->getCol()][openListArr.getNode(i)->getRow()]) == cPtr)
        {
           openx= true;
        }
        
    }
    return openx;
    
}

void PathSolver::searchNodesBeforeAdd(Env env, Node* pPtr){

// Check for the Right node and also check if its available in the open list and If not, add to open list 

if(env[pPtr->getCol()][pPtr->getRow()+ 1] == SYMBOL_EMPTY || env[pPtr->getCol()][pPtr->getRow()+ 1] == SYMBOL_GOAL){

    Node* rightNode = new Node(pPtr->getRow()+ 1,pPtr->getCol(),distanceTravelled + 1);

    if(isNodeOnOpenList(env, &(env[pPtr->getCol()][pPtr->getRow()+ 1])) == false){
        openListArr.addElement(rightNode);
    }
    else{
        delete rightNode;
    }
    std::cout << "Right Triggered" << '\n';
  
}

// Check for the Left node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol()][pPtr->getRow()- 1] == SYMBOL_EMPTY || env[pPtr->getCol()][pPtr->getRow()- 1] == SYMBOL_GOAL)  {
    
    Node* leftNode = new Node(pPtr->getRow()- 1,pPtr->getCol(), distanceTravelled + 1);


    if(isNodeOnOpenList(env, &(env[pPtr->getCol()][pPtr->getRow()- 1])) == false){
        openListArr.addElement(leftNode);
    }
    else{
        delete leftNode;
    }
    std::cout << "Left Triggered" << '\n';
    
}

// Check for the Down node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() + 1][pPtr->getRow()] == SYMBOL_EMPTY || env[pPtr->getCol() + 1][pPtr->getRow()] == SYMBOL_GOAL)  {
    
    Node* downNode = new Node(pPtr->getRow(),pPtr->getCol() + 1, distanceTravelled + 1);

    if(isNodeOnOpenList(env,&(env[pPtr->getCol() + 1][pPtr->getRow()])) == false){
        openListArr.addElement(downNode);
    }
    else{
        delete downNode;
    }

    std::cout << "Down Triggered" << '\n';
    
}

// Check for the Up node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() - 1][pPtr->getRow()] == SYMBOL_EMPTY || env[pPtr->getCol() - 1][pPtr->getRow()] == SYMBOL_GOAL)  {
    
    Node* upNode = new Node(pPtr->getRow(),pPtr->getCol() - 1, distanceTravelled + 1);

    if(isNodeOnOpenList(env, &(env[pPtr->getCol() - 1][pPtr->getRow()])) == false){
        openListArr.addElement(upNode);
    }
    else{
        delete upNode;
    }
    std::cout << "Up Triggered" << '\n';
    
}


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


 
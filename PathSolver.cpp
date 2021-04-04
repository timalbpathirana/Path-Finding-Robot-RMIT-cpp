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



// std::cout << "OpenList Count:" << openListArr.getLength() << '\n'; 
// std::cout << "Closed List Count:" << closedListArr.getLength() << '\n'; 
    std::cout << '\n';
    std::cout << "ROUND 1: " << '\n';
    std::cout << '\n';

    

    // std::cout << "currentP value: " << currentP << '\n';
    // std::cout << "SelectP Method Successful" << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    

    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';
    
    
    

    
    std::cout << '\n';
    std::cout << "ROUND 2: " << '\n';
    std::cout << '\n';

    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);

    
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';
    

    std::cout << '\n';
    std::cout << "ROUND 3: " << '\n';
    std::cout << '\n';

    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';



    std::cout << '\n';
    std::cout << "ROUND 4: " << '\n';
    std::cout << '\n';

    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    std::cout << '\n';
    std::cout << "ROUND 5: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';


    std::cout << '\n';
    std::cout << "ROUND 6: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';


    std::cout << '\n';
    std::cout << "ROUND 7: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';
    /* code */

    std::cout << '\n';
    std::cout << "ROUND 8: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    std::cout << '\n';
    std::cout << "ROUND 9: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    std::cout << '\n';
    std::cout << "ROUND 10: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    std::cout << '\n';
    std::cout << "ROUND 11: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    std::cout << '\n';
    std::cout << "ROUND 12: " << '\n';
    std::cout << '\n';
    selectP();
    searchNodesBeforeAdd(env, currentP);
    closedListArr.addElement(currentP);
    std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 13: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 14: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';


    // std::cout << '\n';
    // std::cout << "ROUND 15: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 16: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 17: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 18: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 19: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 20: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';

    // std::cout << '\n';
    // std::cout << "ROUND 11: " << '\n';
    // std::cout << '\n';
    // selectP();
    // searchNodesBeforeAdd(env, currentP);
    // closedListArr.addElement(currentP);
    // std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    // std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';
    
    // do
    // {
    //     std::cout << '\n';
    //     std::cout << "NEW ROUND: " << '\n';
    //     selectP();
    //     searchNodesBeforeAdd(env, currentP);
    //     closedListArr.addElement(currentP);
    //     std::cout << "OpenList Count: " << openListArr.getLength() << '\n';
    //     std::cout << "ClosedList Count: " << closedListArr.getLength() << '\n';
        
    // } while (env[currentP->getCol()][currentP->getRow()] != SYMBOL_GOAL);
    









}


// Check for the Right node and also check if its available in the open list and If not, add to open list 



// Selecting the simple p

void PathSolver::selectP(){
    //std::cout << "Select P method Triggered" << '\n';
int distance  = INFINITY;
int rounds = openListArr.getArraySize();

for (int y = 0; y < rounds; y++){
    
        for (int i = 0; i < openListArr.getArraySize(); i++){
            
            if (openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr) < distance) {
                distance = openListArr.getNode(i)->getEstimatedDist2Goal(goalPtr);
                minNodeIndex = i;
            }
        }
        //std::cout << "SelectP FFL Done" << '\n';

// Cannot put in the same loop as above for loop needs to finish to the final value for minNodeIndex
        for (int i = 0; i < closedListArr.getLength(); i++){
            if (openListArr.getNode(minNodeIndex) ==            closedListArr.getNode(i)){
               
            }   
    
        }
        //std::cout << "SelectP SFL Done" << '\n';

    }

    // Node* pNode = new Node(openListArr.getNode(minNodeIndex)->getRow(), openListArr.getNode(minNodeIndex)->getCol(), 1);
    
    //std::cout << "Min Distance: " << distance << "\n";
    currentP = openListArr.getNode(minNodeIndex);
    //currentP = &pNode;

    
    std::cout << "p Selection Successfull" << '\n';
    std::cout << "p Node Col:Row "<< currentP->getCol() << ':'<< currentP->getRow() << '\n';
    //std::cout << "Returning P Node pointer: " << pNode <<'\n';

}








void PathSolver::searchNodesBeforeAdd(Env env, Node* pPtr){

// Check for the Right node and also check if its available in the open list and If not, add to open list 

if(env[pPtr->getCol()][pPtr->getRow()+ 1] == SYMBOL_EMPTY){
    
    
    for (int i = 0; i < openListArr.getArraySize(); i++)
    {
        if (&(env[pPtr->getCol()][pPtr->getRow()+ 1]) == &(env[openListArr.getNode(i)->getCol()][openListArr.getNode(i)->getRow()]))
        {
           isNextNodeInOpenList = true;
        }
        else{
            isNextNodeInOpenList = false;
        }
        
    }
    if(!isNextNodeInOpenList){
        
        Node* nextNode = new Node(pPtr->getRow()+ 1,pPtr->getCol(),distanceTravelled + 1);
        openListArr.addElement(nextNode);
        std::cout << "Right Element -> Open List" << '\n';
        
    }
    std::cout << "Right Triggered" << '\n';
  
}

// Check for the Left node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol()][pPtr->getRow()- 1] == SYMBOL_EMPTY)  {
    
    for (int i = 0; i < openListArr.getLength(); i++)
    {
        if (&(env[pPtr->getCol()][pPtr->getRow()- 1]) == &(env[openListArr.getNode(i)->getCol()][openListArr.getNode(i)->getRow()]))
        {
           isNextNodeInOpenList = true;
        }
        else{
            isNextNodeInOpenList = false;
        }
        
    }
    if(!isNextNodeInOpenList){
        Node* nextNode = new Node(pPtr->getRow()- 1,pPtr->getCol(), distanceTravelled+ 1);
        openListArr.addElement(nextNode);
        std::cout << "Left Element -> Open List" << '\n';
        
    }
    std::cout << "Left Triggered" << '\n';
    
}

// Check for the Up node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() - 1][pPtr->getRow()] == SYMBOL_EMPTY)  {
    
    for (int i = 0; i < openListArr.getLength(); i++)
    {
        if (&(env[pPtr->getCol() - 1][pPtr->getRow()]) == &(env[openListArr.getNode(i)->getCol()][openListArr.getNode(i)->getRow()]))
        {
           isNextNodeInOpenList = true;
        }
        else{
            isNextNodeInOpenList = false;
        }
        
    }
    if(!isNextNodeInOpenList){
        Node* nextNode = new Node(pPtr->getRow(),pPtr->getCol() - 1, distanceTravelled + 1);
        openListArr.addElement(nextNode);
        std::cout << "Up Element -> Open List" << '\n';
        
    }
    
    std::cout << "Up Triggered" << '\n';
    
}

// Check for the Down node and also check if its available in the open list and If not, add to open list 
if(env[pPtr->getCol() + 1][pPtr->getRow()] == SYMBOL_EMPTY)  {
    
    for (int i = 0; i < openListArr.getLength(); i++)
    {
        if (&(env[pPtr->getCol() + 1][pPtr->getRow()]) == &(env[openListArr.getNode(i)->getCol()][openListArr.getNode(i)->getRow()]))
        {
           isNextNodeInOpenList = true;
        }
        else{
            isNextNodeInOpenList = false;
        }
        
    }
    if(!isNextNodeInOpenList){
        Node* nextNode = new Node(pPtr->getRow(),pPtr->getCol() + 1, distanceTravelled + 1);
        openListArr.addElement(nextNode);
        std::cout << "Down Element -> Open List" << '\n';
    }
    
    std::cout << "Down Triggered" << '\n';
    
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


 
#include "PathSolver.h"
#include <iostream>


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

    // //Making the closed list and the Open list from NodeList class
    // NodeList* openList;
    // NodeList* closedList;
    // // initialising the start node 
    // int currentRow = 5;
    // int currentCol = 1;
    // int currentDistanceTravelled = 0;
    // Node startNode(currentRow, currentCol, currentDistanceTravelled);
    // Node currentNode(currentRow, currentCol, currentDistanceTravelled);

    
    // // initialising the goal node 
    // // int goalRow = 11;
    // // int goalCol = 5;


    // // added start point to open list and closed list 
    // openList->addElement(&startNode);
    // closedList->addElement(&startNode);



    // //Searching for all the possible nodes to go from current node
    // //search to right
    // if (env[currentCol + 1][currentRow] != '.') {
        
    //     Node nodeObj(startNode.getRow(), startNode.getCol() + 1, startNode.getDistanceTraveled() + 1);
    //     openList->addElement(&nodeObj);
        
       
    // };
    // //search to left
    // if (env[currentCol - 1][currentRow] != '.'){
    //     Node nodeObj(currentRow, currentCol - 1, currentDistanceTravelled + 1);
    //     openList->addElement(&nodeObj);
        
    // };
    // //search to up
    // if (env[currentCol][currentRow + 1] != '.') {
    //     Node nodeObj(currentRow - 1, currentCol, currentDistanceTravelled + 1);
    //     openList->addElement(&nodeObj);
        
    // };
    // //search to down
    // if (env[currentCol][currentRow - 1] != '.') {
    //     Node nodeObj(currentRow + 1, currentCol, currentDistanceTravelled + 1);
    //     openList->addElement(&nodeObj);
        
    // };

    // std::cout << ' ' << std::endl;
    // std::cout << "These are the characters printing from PathSolver.cpp" << std::endl;
    // std::cout << env[currentCol + 1][currentRow] << std::endl;
    // std::cout << env[currentCol - 1][currentRow] << std::endl;
    // std::cout << env[currentCol][currentRow + 1] << std::endl;
    // std::cout << env[currentCol][currentRow - 1] << std::endl;

    
    // //printing the neighbour paths to go. 
    
    // for (int i = 0; i < openList->getLength(); i++){
    //     Node* getB = openList->getNode(i);
    //     std::cout << getB->getRow() << ",";
    //     std::cout << getB->getCol() << ",";
    //     std::cout << getB->getDistanceTraveled() << std::endl;
    // }
    
   

}





NodeList* PathSolver::getNodesExplored(){
    //TODO
    return nullptr;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    return nullptr;
}


//-----------------------------
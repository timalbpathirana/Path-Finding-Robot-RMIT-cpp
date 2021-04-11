#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

using std::cout;
using std::cin;
using std::endl;


// Helper test functions
void testNode();
void testNodeList();
void createNewNode();
void changeNode();
void testEstimatedDistance();
void testNodeListFunctions();
void printTheArray (Env env);



// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3


void printEnvStdout(Env env, NodeList* solution);

int main(int argc, char** argv){

    // Load Environment 
    Env env;
    readEnvStdin(env);

    //createNewNode();
    //changeNode();
    //testEstimatedDistance();
    //testNodeListFunctions();
    //printTheArray (env);

   // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Solve using forwardSearch

    PathSolver* pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);


    // NodeList* exploredPositions = nullptr;
    // exploredPositions = pathSolver->getNodesExplored();

    

    //THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    //NodeList* solution = pathSolver->getPath(env);

    //printEnvStdout(env, solution);


    //delete pathSolver;
    // delete exploredPositions;
    // delete solution;

}

void readEnvStdin(Env env){

    char* arrayPtr = &(env[0][0]);
        for (int row = 0; row< ENV_DIM; row++){
            arrayPtr = &(env[row][0]);
                for (int col = 0; col < ENV_DIM; col++){
                if(!std::cin.eof()){
                std::cin >> *(arrayPtr + col);
                }   
            }
        }
    }

void printEnvStdout(Env env, NodeList* solution) {
    //TODO
     
}

void createNewNode() {
    int row,col,distance;

    // We are testing these edge cases for int
    /*
    1. Int being Zero
    2. Int being 1
    3. Int being 2
    4. Int being 2 < INT_MAX
    5. Int being INT_MAX
    6. Int being INT_MAX + 1
    */
    for (int i = 0; i < 6; i++)
    {
        std::cin >> row; 
        std::cin >> col;
        std::cin >> distance;
        // Make a Node and print out the contents
        Node* node = new Node(row, col, distance);
        std::cout << node->getRow() << ",";
        std::cout << node->getCol() << ",";
        std::cout << node->getDistanceTraveled() << std::endl;
        delete node;
    }
}

void changeNode(){
    //Making variables for std::cin
    int row,col,distance;

    // Getting input 
    std::cin >> row; 
    std::cin >> col;
    std::cin >> distance;

    //Change Node and print again
    Node* node = new Node(2, 4, 1);

    node = new Node(row, col, distance);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testEstimatedDistance(){
    
    int row,col,distance;
    Node* goalNode = new Node(2,2,0);
    // Checking if Manhatten distance always returns a positive value
    // 1. Input cordinated - (0,0)
    // 2. Input cordinates - (1,3)
    // 3. Input cordinates  -(3,1)

    for (int i = 0; i < 3; i++)
    {
        std::cin >> row >> col >> distance;
        Node* node = new Node(row, col, distance);
        int distance = node->getEstimatedDist2Goal(goalNode);
        std::cout << distance << '\n';
    }
    
}


void testNodeListFunctions() {

    // Testing nodelist
    // Make 2 node lists as Open list and Closed list
    NodeList* openList = new NodeList();
    NodeList* closedList = new NodeList();
    
    //Printing the sizes of 2 seperate lists, both should be 0
    std::cout << "OpenList size: " << openList->getLength() << '\n';
    std::cout << "ClosedList size: " << closedList->getLength() << '\n';

    // Add a Node to the openListList, print size = 1
    Node* node1 = new Node(1, 1, 1);
    openList->addElement(node1);
    std::cout << "OpenList size: " << openList->getLength() << std::endl;

    // Add second Node to the openlist and print size = 2
    Node* node2 = new Node(2, 2, 1);
    openList->addElement(node2);
    std::cout << "OpenList size: " << openList->getLength() << std::endl;

    // Test Get-ith and add t close list - should be 0,0,1 and size = 1
    Node* getB = openList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    closedList->addElement(openList->getNode(1));
    std::cout << "CloseList size: " << closedList->getLength() << std::endl;

    // Remove ith element from openlist, size = 1

    openList->removeElement(0);
    std::cout << "OpenList size: " << openList->getLength() << std::endl;
    
    

    // Print out the openlist
    for (int i = 0; i < openList->getLength(); i++){
        Node* getB = openList->getNode(i);
        std::cout << getB->getRow() << ",";
        std::cout << getB->getCol() << ",";
        std::cout << getB->getDistanceTraveled() << std::endl;
    }

    delete openList;
    delete closedList;
    delete node1;
    delete node2;
}

void printTheArray (Env env){
    // char* arrayPtr = &(env[0][0]);
    for (int row = 0; row< ENV_DIM; row++){
        for (int col = 0; col < ENV_DIM; col++){
            std::cout << env[row][col];
        }
        std::cout << '\n';
    }
}

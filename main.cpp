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




#define ROWS 20
#define COLS 20

// Helper test functions
void testNode();
void testNodeList();


// Read a environment from standard input.
void readEnvStdin(Env env);
void printEnv(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3


void printEnvStdout(Env env, NodeList* solution);

int main(int argc, char** argv){
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    //std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
   // testNode();
   // testNodeList();
   // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment 
    Env env;
    readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2





    PathSolver* pathSolver = new PathSolver();

    // //std::cout << "From Timal - Testing Search element" << std::endl;


    pathSolver->forwardSearch(env);




    // NodeList* exploredPositions = nullptr;
    // exploredPositions = pathSolver->getNodesExplored();

    // // Get the path
    // // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    //NodeList* solution = pathSolver->getPath(env);

    //printEnv(env);
    //printEnvStdout(env, nodeListObj);


    // delete pathSolver;
    // delete exploredPositions;
    // delete solution;

}

void readEnvStdin(Env env){
  char c; 
  
  //std::string line;
    std::ifstream is("input.txt");     // open file
         // loop getting single characters
         
    for (int x =0; x < ENV_DIM; x++){
        for (int y = 0; y < ENV_DIM ; y++)
        { 
            is.get(c);
            env[y][x] = c;
            std::cout << env[y][x];

        }
            
        }
    std::cout << std::endl;
    is.close();

// Trying to print the the nodes with '.' characters from the env[][] array.
    // for (int row = 0; row < ROWS; row++){
    //     for (int col = 0; col < COLS; col++){
    //         if (env[row][col] == '.'){
    //             std::cout << "New node  ";
    //             std::cout << " R:" << col << " C:" << row << std::endl;
                
    //         }
        
            
    //  }   
     
    // }
}


void printEnv(Env env){
    for (int row = 0; row < ROWS; row++){
        for (int col = 0; col < COLS; col++){
            std::cout << env[row][col] << ' ';
     }   
     std::cout << std::endl;
  }
    
};

void printEnvStdout(Env env, NodeList* solution) {
    //TODO
    for (int i = 0; i < ROWS; i++)
  {
     for (int n = 0; n < COLS; n++)
     {
         std::cout << env[i][n];
     }   
  }
    std::cout << std::endl;
  
}

void testNode() {
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node* node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList() {
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList* nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node* b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node* b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node* getB = nodeList->getNode(0);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    std::cout << "PRINTING OUT A NODELIST" << std::endl;

    for (int i = 0; i < nodeList->getLength(); i++){
        Node* getB = nodeList->getNode(i);
        std::cout << getB->getRow() << ",";
        std::cout << getB->getCol() << ",";
        std::cout << getB->getDistanceTraveled() << std::endl;
    }

}
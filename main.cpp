/*
short 1-paragraph description. 
For M1 and M2, I first tried to read the maze correctly into the 2D array and then printed that out to make sure I read that correctly. Then I searched for S node and G node and made pointers to those 2 positions. I made 2 objects from the NodeList class to get 2 arrays( Openlist and closeList). Then I added the S node to the open list before I start the search for neighbours. Then I started the search and add the neighbour nodes only if they are NOT inside the closed list. And then I add the current node to the closed list. So this untill I reach the G node. 

Then I copied the closed list using copy constructor and use that to filtered the nodes for backtracking. To filteration, I used the distance travelled paramter to get the L-1, L-2 etc nodes. Then I made another nodelist object and I reversed the nodes inside the copied array and add to the new array. 

For M3 last part, I simply used if statements to check the next node, and if the next node going right, left, up or down, I added the symboles accordinly. 

ISSUES I HAVE ENCOUNTERED:
1. Got heaps of segmentation faults. 
2. Maze array printed in unexpected ways and missing some characters or sometimes a half of the bottom line
3. Sometimes made duplicate methods which do basically the same thing.
4. Issues with how to use the copy constructor.
5. pointer being freed was not allocated error.

Online materials I have used,
1. https://www.guru99.com/cpp-dynamic-array.html#4
2. https://stackoverflow.com/questions/34168053/reverse-array-pointer-in-c
3. https://www.geeksforgeeks.org/program-reverse-array-using-pointers/
4. https://stackoverflow.com/questions/7935603/c-pointer-being-freed-was-not-allocated-error
5. http://www.cplusplus.com/forum/beginner/219983/
6. http://www.cplusplus.com/doc/tutorial/arrays/

*/


#include <iostream>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"


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

    // std::cout << "TESTING STARTED" << std::endl << std::endl;

    //createNewNode();
    //changeNode();
    //testEstimatedDistance();
    //testNodeListFunctions();
    //printTheArray (env);

    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Milestone 1 and 2;
    PathSolver* pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);
    delete pathSolver;

    // Milestone 2;
    NodeList* exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();
    
    // Milestone 3;
    NodeList* solution = pathSolver->getPath(env);    
 
    // Milestone 3;
    printEnvStdout(env, solution);

    delete exploredPositions;
    delete solution;

}

void readEnvStdin(Env env){

    char* arrayPtr = &(env[0][0]);
        for (int row = 0; row< ENV_DIM; row++){
            arrayPtr = &(env[row][0]);
                for (int col = 0; col < ENV_DIM; col++){
                if(!std::cin.eof()){
                std::cin >> *(arrayPtr + col);
                }  
                else{
                    
                } 
            }
        }
    }

void printEnvStdout(Env env, NodeList* solution) {



for (int i = 0; i < solution->getLength() - 1; i++)
{
     if (solution->getNode(i+1)->getCol() > solution->getNode(i)->getCol() && 
     env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol() != SYMBOL_GOAL]){
         
        // then node 1 should be on right side >
        env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol()] = SYMBOL_RIGHT;
        // std::cout << "Right works" << '\n';
    }
    
    if (solution->getNode(i+1)->getCol() < solution->getNode(i)->getCol() && env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol()] != SYMBOL_GOAL)
    {
        // then node 1 should be on left side <
        env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol()] = SYMBOL_LEFT;
        // std::cout << "left works" << '\n';
    }
    
    if (solution->getNode(i +1)->getRow() > solution->getNode(i)->getRow() && env[solution->getNode(i +1)->getRow()][solution->getNode(i +1)->getCol()] != SYMBOL_GOAL)
    {
        // then node 1 should be down v
        
        env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol()] = SYMBOL_BOTTOM;
        // std::cout << "down works" << '\n';
    }
    
    if (solution->getNode(i +1)->getRow() < solution->getNode(i)->getRow() && env[solution->getNode(i +1)->getRow()][solution->getNode(i +1)->getCol()] != SYMBOL_GOAL)
    {
        // then node 1 should be up ^
        env[solution->getNode(i+1)->getRow()][solution->getNode(i+1)->getCol()] = SYMBOL_TOP;
        // std::cout << "up works" << '\n';

    }
}

for (int row = 0; row < ENV_DIM; row++){
    for (int col = 0; col < ENV_DIM; col++){
        std::cout << env[row][col];
    }
    std::cout << '\n';
    
    } 

}


void createNewNode() {
    int row,col,distance;

    //testing these edge cases for int
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

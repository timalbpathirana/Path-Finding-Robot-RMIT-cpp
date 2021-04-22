#ifndef COSC_ASSIGN_ONE_PATHSOLVER
#define COSC_ASSIGN_ONE_PATHSOLVER 

#include "Node.h"
#include "NodeList.h"
#include "Types.h"

class PathSolver{
public:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Destructor
    PathSolver();
    ~PathSolver();

    // Execute forward search algorithm
    // To be implemented for Milestone 2
    void forwardSearch(Env env);

    // Get a DEEP COPY of the explored NodeList in forward search
    // To be implemented for Milestone 2
    NodeList* getNodesExplored();

    // Execute backtracking and Get a DEEP COPY of the path the 
    // robot should travel
    // To be implemented for Milestone 3
    NodeList* getPath(Env env);
    
    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    void selectP();
    void findStartNode (Env env);
    void searchNodesBeforeAdd(Env env, Node* pPtr);
    bool isNotOnClosedList(Node* nodePtr);
    void searchNodesToGetPath(Env env, Node* nPtr);


private:
    /*                                           */
    /* DO NOT MOFIFY THESE VARIABLES             */
    /*                                           */

    
    // Nodes explored in forward search algorithm
    //NodeList* nodesExplored;

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */

    // Creating all the global varibles and pointers and initialising them
    Node* startPtr = nullptr;
    Node* goalPtr = nullptr;
    Node* currentP = nullptr;
    NodeList* closedListDeepCopyPtr = nullptr;

    bool isNextNodeInOpenList;
    int minNodeIndex =0 ;
    int distanceTravelled = 0;

    // Making node objects to create openlist array and closedlist array
    NodeList* openListArr = new NodeList();
    NodeList* closedListArr = new NodeList();
    
    
};




#endif //COSC_ASSIGN_ONE_PATHSOLVER
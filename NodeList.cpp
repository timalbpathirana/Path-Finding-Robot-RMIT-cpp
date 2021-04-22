#include "NodeList.h"
#include "Node.h"
#include "Types.h"
#include <iostream> 
#include <vector>

int length = 0;

/*
provides a method for storing a list of node objects as used in pseudo-code above.
TheNodeListclass provides a method for storing a list ofNodeobjects. It stores anarrayofNodeobjects.Since it’s an array we also need to track the number of position objects in theNodeList.
*/


NodeList::NodeList(){
}

NodeList::~NodeList(){
    
}

// making a deep copy
NodeList::NodeList(NodeList& other){
    for (int i = 0; i < other.getLength(); i++)
    {
        nodeListArray[i] = other.getNode(i);
        length = other.getLength();
    }
    
}
/* Number of nodes currently in the NodeList */
int NodeList::getLength() 
{
    return length;

}


// Add a COPY node element to the BACK of the nodelist.
void NodeList::addElement(Node* newPos){
    // Creating a new node object
    Node* newNodePtr = new Node(newPos->getRow(), newPos->getCol(), newPos->getDistanceTraveled());
    // Making sure nodes will never go beyond the end of the array.
    if(length < NODE_LIST_ARRAY_MAX_SIZE){
        nodeListArray[length] = newNodePtr;
        length = length + 1;
    } 
}

// Deleting the iTH element from the array
void NodeList::removeElement(int i){
    // deleting ith place( i-1 index)
    for (int y = (i -1); y < NODE_LIST_ARRAY_MAX_SIZE; y++)
    {   // copying next element 
        nodeListArray[y] = nodeListArray[y + 1]; 
    }
    length = length - 1;  
}

Node* NodeList::getNode(int i){
    //returning the memory address of the i th Node,
    return nodeListArray[i];
    
}



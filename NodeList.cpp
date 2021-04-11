#include "NodeList.h"
#include "Node.h"
#include "Types.h"
#include <iostream> 
#include <vector>

int length;
/*

provides a method for storing a list of node objects as used in pseudo-code above.
TheNodeListclass provides a method for storing a list ofNodeobjects. It stores anarrayofNodeobjects.Since it’s an array we also need to track the number of position objects in theNodeList.

*/
//Creating a std::vector array
//int jimmy [3][5];   // is equivalent to
//int jimmy [15];     // (3 * 5 = 15)  

Node nodeListArray[NODE_LIST_ARRAY_MAX_SIZE];



NodeList::NodeList(){
    length = 0;
}

NodeList::~NodeList(){
    
}

// making a deep copy
NodeList::NodeList(NodeList &other){
    // TODO

}

// Number of nodes currently in the NodeList
int NodeList::getLength(){
    // int arrSize = sizeof(nodeListArray)/sizeof(nodeListArray[0]);
    // return arrSize;
    return length;

}


// Add a COPY node element to the BACK of the nodelist.



void NodeList::addElement(Node* newPos){
    // need to create a new node object
    
    Node node(newPos->getRow(), newPos->getCol(), newPos->getDistanceTraveled());
    // Making sure nodes will never go beyond the end of the array.
    if(length < NODE_LIST_ARRAY_MAX_SIZE){
        nodeListArray[length] = node;
    //nodeListVector.push_back(node);
        length = length + 1;
    } 
}

// deleted the iTH element from the array
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
    return &nodeListArray[i];
    
}



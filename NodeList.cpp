#include "NodeList.h"
#include "Node.h"
#include "Types.h"
#include <iostream> 


//  provides a method for storing a list of node objects as used in pseudo-code above.
// TheNodeListclass provides a method for storing a list ofNodeobjects. It stores anarrayofNodeobjects.Since it’s an array we also need to track the number of position objects in theNodeList.
int length;
int arraySize = 0;
Node array[NODE_LIST_ARRAY_MAX_SIZE];


NodeList::NodeList(){
    
}

NodeList::~NodeList(){
    
}

// making a deep copy
NodeList::NodeList(NodeList &other){
    // TODO

    //length = other.length;
    //NodeList::addElement() = other.addElement();

}

// Number of nodes currently in the NodeList
int NodeList::getLength(){
    return length;
}

void NodeList::setLength(int length){
    this->length =  length;
}

// Add a COPY node element to the BACK of the nodelist.
void NodeList::addElement(Node* newPos){
    // need to create a new node object
    
    Node node(newPos->getRow(), newPos->getCol(), newPos->getDistanceTraveled());
    array[arraySize++] = node;
    length++;
}

Node* NodeList::getNode(int i){
    
    //returning the memory address of the i th Node,
   return &(array[i]);
}



#include "NodeList.h"
#include "Node.h"
#include "Types.h"
#include <iostream> 
#include <vector>


//  provides a method for storing a list of node objects as used in pseudo-code above.
// TheNodeListclass provides a method for storing a list ofNodeobjects. It stores anarrayofNodeobjects.Since it’s an array we also need to track the number of position objects in theNodeList.
int length = 0;

//Creating a vector array 
std::vector<Node> nodeListVector;



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
    nodeListVector.push_back(node);
    length++;
}

// deleted the iTH element from the array
void NodeList::removeElement(int i){
    nodeListVector.erase(nodeListVector.begin() + (i-1) );
}

int NodeList::getArraySize(){
    return this->nodeListVector.size();
}

Node* NodeList::getNode(int i){
    
    //returning the memory address of the i th Node,
    
        return &(nodeListVector.at(i));
    
}



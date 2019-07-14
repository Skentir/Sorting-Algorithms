#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nodeVariable;
	struct Node* (nextNode);
}Node;

typedef struct {
    struct Node* (nodes);
    int linkSize;
}LinkedList;
    
LinkedList createList(int nSize){
    LinkedList linkList;
    
    linkList.linkSize = nSize;
    linkList.nodes = (Node*) malloc(sizeof(Node) * nSize);
    
    return linkList;
}
int main() {
    return 0;
}

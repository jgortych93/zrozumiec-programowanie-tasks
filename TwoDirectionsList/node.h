#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

typedef struct Node{

    int value;
    Node* nextNode;
    Node* prevNode;

} Node;

#endif // NODE_H

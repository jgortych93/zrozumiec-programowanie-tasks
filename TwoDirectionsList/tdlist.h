#ifndef TDLIST_H
#define TDLIST_H

#include "node.h"

class TDList
{
    Node *head,*tail;
    uint32_t counter;
public:
    TDList();
    ~TDList();

    void pushFront(const int &value);
    void pushBack(const int &value);

    Node *getHeadElement() const;
    Node *getTailElement() const;
    Node *getElementAtIndex(const uint32_t& index) const;

    int getValueAtIndex(const uint32_t& index) const;

    void removeElementAtIndex(const uint32_t& index);
};

#endif // TDLIST_H

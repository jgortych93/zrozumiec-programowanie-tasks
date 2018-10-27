#include "tdlist.h"
#include <stdexcept>

TDList::TDList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

TDList::~TDList()
{

}

void TDList::pushFront(const int &value)
{

    Node *newNode = new Node;
    newNode->value = value;
    newNode->prevNode = nullptr;
    newNode->nextNode = this->head;

    if (newNode->nextNode)
        newNode->nextNode->prevNode = newNode;

    this->head = newNode;
    if (nullptr == this->tail)
        this->tail = newNode;

    ++(this->counter);
}

void TDList::pushBack(const int &value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->prevNode = this->tail;

    if(newNode->prevNode)
        newNode->prevNode->nextNode = newNode;

    newNode->nextNode = nullptr;

    this->tail = newNode;
    if (nullptr == this->head)
        this->head = newNode;

    ++(this->counter);
}

int TDList::getValueAtIndex(const uint32_t &index) const
{
    return this->getElementAtIndex(index)->value;
}


Node* TDList::getElementAtIndex(const uint32_t &index) const
{
    if (index >= this->counter)
        throw new out_of_range("Too big index number");

    if (0u == index)
        return getHeadElement();

    Node* currentNode = this->head;

    for (uint32_t i = 0; i <= index; ++i)
    {
        if (index == i)
        {
            return currentNode;
        }

        currentNode = currentNode->nextNode;
    }
}

Node* TDList::getHeadElement() const
{
    return this->head;
}

Node* TDList::getTailElement() const
{
    return this->tail;
}

void TDList::removeElementAtIndex(const uint32_t &index)
{
    if (1u ==this->counter)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

   Node* toRemoval = this->getElementAtIndex(index);

   if (this->head == toRemoval)
   {
       toRemoval->nextNode->prevNode = nullptr;
       this->head = toRemoval->nextNode;
       toRemoval->nextNode = nullptr;
   }
   else if(this->tail == toRemoval)
   {
       toRemoval->prevNode->nextNode = nullptr;
       this->tail = toRemoval->prevNode;
       toRemoval->prevNode = nullptr;
   }
   else
   {
       toRemoval->nextNode->prevNode = toRemoval->prevNode;
       toRemoval->prevNode->nextNode = toRemoval->nextNode;
   }

   toRemoval = nullptr;

}

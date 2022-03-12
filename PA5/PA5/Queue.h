#pragma once

#include "QueueNode.h"


class Queue {
public: // Member functions

    Queue();
    //Queue(const Queue& copy); //deep copy 
    ~Queue();

   

    QueueNode* getpHead();
    QueueNode* getpTail();

    void setpHead(QueueNode* newpHead);
    void setpTail(QueueNode* newpTail);

    bool enqueue(Data* newData, LinkedList* newpHead);
    QueueNode* dequeue(); 
    void printQueue();

    bool isEmpty(); 
   
private:
    QueueNode* pHead;
    QueueNode* pTail;

    QueueNode* makeNode(Data* newData, LinkedList* newpHead); 

    void destroyList();
    void destroyListHelper(QueueNode* const pMem); 
    
    
};

    ostream& operator<< (ostream& os, Queue&  output);
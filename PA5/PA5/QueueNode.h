#pragma once

#include "Data.h"
#include "LinkedList.h"


class QueueNode{
public: // Member functions

    QueueNode(Data* newData, LinkedList* newpHead); 
    QueueNode(const QueueNode& copyQueue);  

    ~QueueNode();



    Data* getpData();
    QueueNode* getpNext();

    LinkedList* getppHead() {
        return ppHead;
    }

    void setpData(Data* newData);
    void setpNext(QueueNode* newData); 

    void setppHead(LinkedList* newData) {
        ppHead = newData; 
    }


private:
    Data* pData;    // The memory for Data will need to be allocated on the heap as well!
    LinkedList* ppHead; 
    QueueNode* pNext;
};

ostream& operator<< (ostream& os, QueueNode&  output); 

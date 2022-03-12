#include "Queue.h"

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

//Queue::Queue(const Queue& copy)
//{
//	if (copy.pHead == nullptr) {
//		return;
//	}
//
//	QueueNode* tmp = copy.pHead;
//
//	QueueNode* newNode = new QueueNode(tmp->getpData());  
//
//	//newNode->setpData(tmp->getpData());
//	newNode->setpNext(nullptr);
//
//	QueueNode* current = newNode;
//
//	tmp = tmp->getpNext();
//
//	while (tmp != nullptr) {
//		current->setpNext(new QueueNode(tmp->getpData()));
//
//		current = current->getpNext();
//
//		//current->setpData(tmp->getpData());
//
//		current->setpNext(nullptr);
//
//		if (tmp->getpNext() == nullptr) {
//			pTail = tmp;  
//		}
//
//		tmp = tmp->getpNext(); 
//		
//	}
//	pHead = newNode; 
//}

Queue::~Queue()
{
	destroyList();
}

ostream& operator<<(ostream& os,  Queue&  output)
{
	os << "Customer Number : " << output.getpHead()->getpData()->getCustomerNumber() << endl << "Service Time: " << output.getpHead()->getpData()->getServiceTime() << endl << "Total Time: " << output.getpHead()->getpData()->getTotalTime();
	// TODO: insert return statement here

	return os;
}

QueueNode* Queue::getpHead()
{
	return pHead; 
}

QueueNode* Queue::getpTail()
{
	return pTail;
}

void Queue::setpHead(QueueNode* newpHead)
{
	pHead = newpHead;
}

void Queue::setpTail(QueueNode* newpTail)
{
	pTail = newpTail;
}

bool Queue::enqueue(Data* newData, LinkedList* newpHead)
{
	bool success = false;

	QueueNode* pMem = makeNode(newData, newpHead);  

	if (pMem != nullptr) {

		success = true;
		pMem->setpNext(pHead); 
		setpHead(pMem);
		//pHead = pMem; 
		if (pMem->getpNext() == nullptr) {
			setpTail(pMem);
			//pTail = pMem;  
		}
	}

	return success;
}

QueueNode* Queue::dequeue()  
{
	if (pTail != nullptr) {
		Data* tmpData = pTail->getpData();
		LinkedList* tmpList = pTail->getppHead();
		QueueNode* storeNode = new QueueNode(pTail->getpData(), pTail->getppHead());

		QueueNode* tmpNode = pHead; 

		if (tmpNode->getpNext() != nullptr) { 

			while (tmpNode->getpNext()->getpNext() != nullptr) { 
				tmpNode = tmpNode->getpNext(); 
			}

			delete pTail;
			pTail = tmpNode; 
			pTail->setpNext(nullptr);  
		}
		else {
			delete pHead; 
			pHead = nullptr;  
		}


		return storeNode;	
	}
	else {
		return nullptr; 
	}
}

void Queue::printQueue()
{
	QueueNode* pCur = pHead;

	while (pCur != nullptr) {
		cout << "Customer Number: " << pCur->getpData()->getCustomerNumber() << endl << "Service Time: " << pCur->getpData()->getServiceTime() << endl << "Total Time: " << pCur->getpData()->getTotalTime() << endl << "|" << endl;
		//cout << pCur << endl; 
		pCur = pCur->getpNext(); 
	}


}

bool Queue::isEmpty()
{
	bool empty = false;

	if (pHead == nullptr) {
		empty = true;
		return empty;
	}
}

QueueNode* Queue::makeNode(Data* newData, LinkedList* newpHead)
{
	QueueNode* pMem = new QueueNode(newData, newpHead); 

	return pMem; 
}

void Queue::destroyList()
{
	destroyListHelper(pHead); 
}

void Queue::destroyListHelper(QueueNode* const pMem)
{
	if (pMem != nullptr) {
		destroyListHelper(pMem->getpNext()); 
		delete pMem;
		
	}
}



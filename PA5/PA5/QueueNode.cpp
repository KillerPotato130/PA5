#include "QueueNode.h"



QueueNode::QueueNode( Data* newData, LinkedList* newpHead) 
{

	ppHead = newpHead; 
	pData = newData; 
	pNext = nullptr;
}

QueueNode::QueueNode(const QueueNode& copyQueue)
{  
	pData->setCustomerNumber(copyQueue.pData->getCustomerNumber()); 
	pData->setServiceTime(copyQueue.pData->getServiceTime());
	pData->setTotalTime(copyQueue.pData->getTotalTime());
	pNext = copyQueue.pNext; 
}

QueueNode::~QueueNode() 
{
	//delete pData; 
}

Data* QueueNode::getpData()
{
	return pData; 
}

QueueNode* QueueNode::getpNext()
{
	return pNext;
}

void QueueNode::setpData(Data* newData)
{
	pData = newData; 
}

void QueueNode::setpNext(QueueNode* newData)
{
	pNext = newData;
}

ostream& operator<<(ostream& os, QueueNode&  output)
{

	os << "Customer Number : " << output.getpData()->getCustomerNumber() << endl << "Service Time: " << output.getpData()->getServiceTime() << endl << "Total Time: " << output.getpData()->getTotalTime();
	// TODO: insert return statement here


	return os;
}

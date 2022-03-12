#pragma once

#include "Data.h"


class ListNode {
private:
	string groceryItem;
	ListNode* pNext;
public:
	friend class LinkedList;
	ListNode(string newGroceryItem) {
		this->groceryItem = newGroceryItem;
	}

	ListNode* getpNext() {
		return pNext; 
	}

	string getGroceryItem() { 
		return groceryItem;  
	}

	void setpNext(ListNode* newData) {
		pNext = newData;
	}

	void setGroceryItem(string newItem) {
		groceryItem = newItem; 
	}


};


class LinkedList {
private:
	ListNode* ppHead; 

	ListNode* makeNode(string newItem) {
		ListNode* pMem = new ListNode(newItem); 
		return pMem; 
	}

	void destroyList() {
		destroyListHelper(ppHead); 
	}
	void destroyListHelper(ListNode* const pMem) {
		if (pMem != nullptr) {
			destroyListHelper(pMem->getpNext());
			delete pMem;

		}
	}
public:
	LinkedList() {
		this->ppHead = nullptr;
	}

	~LinkedList() {
		destroyList(); 
	}

	ListNode* getpHead() {
		return ppHead;
	}

	void setpHead(ListNode* newData) {
		ppHead = newData; 
	}

	void insertAtFront(string newItem) {
		ListNode* pMem = makeNode(newItem);

		if (pMem != nullptr) {
			pMem->setpNext(ppHead);
			ppHead = pMem;  
		}
	}

	void printList() {
		ListNode* pCur = ppHead;
		while (pCur != nullptr) {
			cout << pCur->getGroceryItem() << "->";
			pCur = pCur->getpNext(); 
		}
	}

};
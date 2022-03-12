#include "TestApp.h"

void runTestSuite(void)
{
	TestApp t;
	t.testEnqueueEmpty();
	system("pause");
	system("cls");
	t.testEnqueue(); 
	system("pause");
	system("cls");
	t.testDeQueueOneNode();
	system("pause");
	system("cls");
	t.testDeQueueTwoNodes();


	system("pause");
	system("cls");
	t.runSimulation();
	system("pause");
	system("cls");
}

void TestApp::testEnqueueEmpty(void)
{
	{

		Data* testData = new Data(1, 3, 10); 
		LinkedList* list = nullptr;
		Queue testQueue;

		testQueue.enqueue(testData, list);  
		   

		if (testQueue.getpHead() != nullptr) {
			testQueue.printQueue();
			cout << "Test \"testEnqueueEmpty\" passed" << endl << endl;
		}
		else {
			cout << "Test \"testEnqueueEmpty\" failed" << endl << endl;
		}
	}
}

void TestApp::testEnqueue(void)
{

	int x = 1;
	Data* testData = new Data(1, 3, 10);
	Data testData2(2, 4, 14);
	LinkedList* list = nullptr;
	Queue testQueue;

	
	testQueue.enqueue(testData, list); 
	//testData = &testData2; 
	testData = new Data(2, 4, 14); 
	testQueue.enqueue(testData, list);  

	if (testQueue.getpHead()->getpNext() != nullptr) {
		testQueue.printQueue();
		cout << "Test \"testEnqueue\" passed" << endl << endl;
	}
	else {
		cout << "Test \"testEnqueue\" failed" << endl;
	}
}

void TestApp::testDeQueueOneNode(void)
{
	Data* testData = new Data(1, 3, 10);
	//Data testData(1, 3, 10);
	LinkedList* list = nullptr;
	QueueNode* testDataEmpty; 
	Queue testQueue;

	testQueue.enqueue(testData, list); 

	if (testQueue.getpHead() != nullptr) {
		testQueue.printQueue();
		cout << "One Node initialized" << endl << endl;
	}

	testDataEmpty = testQueue.dequeue();

	if (testQueue.getpHead() == nullptr) {
		cout << "Dequeue test part 1 passed" << endl;

		if (testDataEmpty->getpData()->getCustomerNumber() != 0) {
			cout << "Returned Customer Number: " << testDataEmpty->getpData()->getCustomerNumber() << endl;
			cout << "Returned Service Time: " << testDataEmpty->getpData()->getServiceTime() << endl;
			cout << "Returned Total Time: " << testDataEmpty->getpData()->getTotalTime() << endl;
			cout << "Dequeue test part 2 passed" << endl;
		}
		else {
			cout << "Dequeue test part 2 failed" << endl;
		}
	}
	else {
		cout << "Dequeue test part 1 failed - couln't test part 2" << endl;
	}

}

void TestApp::testDeQueueTwoNodes(void)
{

	Data testData(1, 3, 10);
	Data testData2(2, 4, 14); 
	QueueNode* testDataEmpty; 
	LinkedList* list = nullptr; 
	Queue testQueue;

	testQueue.enqueue(&testData, list); 
	
	//testData = testData2;  
	testQueue.enqueue(&testData2, list); 

	if (testQueue.getpHead() != nullptr) {
		testQueue.printQueue();
		cout << "two Nodes initialized" << endl << endl;
	}

	testDataEmpty = testQueue.dequeue();

	if (testQueue.getpHead()->getpNext() == nullptr) {
		cout << "Dequeue test part 1 passed" << endl << endl;

		cout << "New Queue: " << endl;
		testQueue.printQueue();
		cout << endl;
		if (testDataEmpty->getpData()->getCustomerNumber() != 0) {
			cout << "Returned Customer Number: " << testDataEmpty->getpData()->getCustomerNumber() << endl; 
			cout << "Returned Service Time: " << testDataEmpty->getpData()->getServiceTime() << endl; 
			cout << "Returned Total Time: " << testDataEmpty->getpData()->getTotalTime() << endl; 
			cout << "Dequeue test part 2 passed" << endl;
		}
		else {
			cout << "Dequeue test part 2 failed" << endl;
		}
	}
	else {
		cout << "Dequeue test part 1 failed - couln't test part 2" << endl;
	}

}

void TestApp::runSimulation(void)
{
	Data* expressLaneData = new Data(0, 0, 0); 
	QueueNode* returnedExpressLaneData;  
	Data* normalLaneData = new Data(0, 0, 0);
	QueueNode* returnedNormalLaneData;

	LinkedList* list = nullptr;  

	Queue expressLane;
	Queue normalLane; 

	int totalTime = 0, totalExpressLaneCustomersCheckedOut = 0, totalNormalLaneCustomersCheckedOut = 0;
	int expressLaneAverageWait = 0, normalLaneAverageWait = 0;
	int expressCustomerNumber = 0, normalCustomerNumber = 0; 
	int expressLaneArrivalTime = 0, normalLaneArrivalTime = 0;
	int expressLaneServiceTime = 0, normalLaneServiceTime = 0;
	int expressLaneDepartureTime = 0, normalLaneDepartureTime = 0;
	bool acceptNewExpressArrival = true, acceptNewNormalArrival = true;


	for (int x = 0; x <= 1440; x++) {
							   /*
			*************************************
			//	                               //
			//           Express Lane          //
			//							       //	
			*************************************
  												

  													
			*************************************
			//	                               //
			//    Arrival into Express Lane    //
			//							       //
			*************************************
							   */		

		if (acceptNewExpressArrival == true) { 	
			expressLaneArrivalTime = (rand() % 5 + 1) + x; 
			acceptNewExpressArrival = false; 
		}
		if (expressLaneArrivalTime == x) {
			expressLaneServiceTime = rand() % 5 + 1; 
			expressCustomerNumber++;
			expressLaneData = new Data(expressCustomerNumber, expressLaneServiceTime, x);
			expressLane.enqueue(expressLaneData, list);  
			cout << "Express Lane Arrival-" << "Customer Number: " << expressLane.getpHead()->getpData()->getCustomerNumber() << " ";
			cout << "Total Time Esapsed: " << x << endl; 
			
			acceptNewExpressArrival = true;   
		}

							   /*
			*************************************
			//	                               //
			//   Departure from Express Lane   //
			//							       //
			*************************************
							   */
		if (expressLane.getpHead() != nullptr) {
			if (expressLane.getpHead()->getpNext() == nullptr) {
				expressLaneDepartureTime = x + expressLane.getpHead()->getpData()->getServiceTime();
			}
			if (expressLaneDepartureTime == x) {
				returnedExpressLaneData = expressLane.dequeue();
				cout << "Express Lane Departure-" << "Customer Number: " << returnedExpressLaneData->getpData()->getCustomerNumber() << " ";
				cout << "Time in Line: " << (x - returnedExpressLaneData->getpData()->getTotalTime()) << endl;
				totalExpressLaneCustomersCheckedOut += 1;
				expressLaneAverageWait += (x - returnedExpressLaneData->getpData()->getTotalTime());  
				//cout << " " << "Total Time Esapsed: " << x << endl; 
				if (expressLane.getpTail() != nullptr) {
					expressLaneDepartureTime = x + expressLane.getpTail()->getpData()->getServiceTime();
				}
			}
		}



//*********************************************************************************************************************************************




						       /*
			*************************************
		    //	                               //
		    //           Normal Lane           //
		    //							       //
		    *************************************



		    *************************************
		    //	                               //
		    //     Arrival into Normal Lane    //
		    //							       //
		    *************************************
							   */

		if (acceptNewNormalArrival == true) {
			do {
				normalLaneArrivalTime = (rand() % 8 + 1) + x;
			} while (normalLaneArrivalTime < 3);
			acceptNewNormalArrival = false;   
		}
		if (normalLaneArrivalTime == x) {
			
				normalLaneServiceTime = rand() % 8 + 1;
				if (normalLaneServiceTime < 3) {
					normalLaneServiceTime = rand() % 8 + 1;
				}
				
			normalCustomerNumber++;
			normalLaneData = new Data(normalCustomerNumber, normalLaneServiceTime, x);
			normalLane.enqueue(normalLaneData, list);  
			cout << "Normal Lane Arrival-" << "Customer Number: " << normalLane.getpHead()->getpData()->getCustomerNumber() << " ";
			cout << "Total Time Esapsed: " << x << endl;

			acceptNewNormalArrival = true; 
		}

						       /*
			*************************************
			//	                               //
			//    Departure from Normal Lane   //
			//							       //
			*************************************
							   */
		if (normalLane.getpHead() != nullptr) {
			if (normalLane.getpHead()->getpNext() == nullptr) {
				normalLaneDepartureTime = x + normalLane.getpHead()->getpData()->getServiceTime();
			}
			if (normalLaneDepartureTime == x) {
				returnedNormalLaneData = normalLane.dequeue();
				cout << "Normal Lane Departure-" << "Customer Number: " << returnedNormalLaneData->getpData()->getCustomerNumber() << " "; 
				cout << "Time in Line: " << (x - returnedNormalLaneData->getpData()->getTotalTime()) << endl; 
				totalNormalLaneCustomersCheckedOut += 1;
				normalLaneAverageWait += (x - returnedNormalLaneData->getpData()->getTotalTime()); 
				//cout << " " << "Total Time Esapsed: " << x << endl; 
				if (normalLane.getpTail() != nullptr) {
					normalLaneDepartureTime = x + normalLane.getpTail()->getpData()->getServiceTime(); 
				}
			}
		}



		if (x % 10 == 0) {
			cout << endl << "Total Time Esapsed: " << x << endl << "Express Lane: " << endl << "Back" << endl << "|" << endl;
			expressLane.printQueue();
			cout << "Front ^";
			cout << endl;
			cout << "Normal Lane: " << endl << "Back" << endl << "|" << endl;
			normalLane.printQueue(); 
			cout << "Front ^";
			cout << endl;
		}
	}


	expressLaneAverageWait = expressLaneAverageWait / totalExpressLaneCustomersCheckedOut;
	cout << endl << endl << "Total Express Lane Customers Serviced: " << totalExpressLaneCustomersCheckedOut << endl;
	cout << "Express Lane Average Wait Time: " << expressLaneAverageWait << endl << endl;
	if (totalNormalLaneCustomersCheckedOut != 0) {
		normalLaneAverageWait = normalLaneAverageWait / totalNormalLaneCustomersCheckedOut;
		cout << endl << endl << "Total Normal Lane Customers Serviced: " << totalNormalLaneCustomersCheckedOut << endl;
		cout << "Normal Lane Average Wait Time: " << normalLaneAverageWait << endl << endl;
	}
	else if (totalNormalLaneCustomersCheckedOut == 0) {
		cout << endl << "No Customers checkout in the time frame!";
	}

	
}

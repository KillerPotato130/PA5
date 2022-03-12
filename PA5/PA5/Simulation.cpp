#include "Simulation.h"

int Launcher::menu()
{
	int option = 0;
	bool status = true;

	while (status == true) {
		cout << "1) Run tests" << endl << "2) Run Simulation" << endl << "3) Exit" << endl << "Your Choice: ";
		cin >> option;
		if (option > 0 && option < 4) {
			status = false;
		}
		else {
			cout << "Invalid Option!" << endl;
		}
		
	}


	return option;
}

void Launcher::simulation(void)
{
	Data* expressLaneData = new Data(0, 0, 0);
	QueueNode* returnedExpressLaneData; 
	Data* normalLaneData = new Data(0, 0, 0);
	QueueNode* returnedNormalLaneData; 

	ListNode* expressLaneItem = new ListNode("");
	ListNode* normalLaneItem = new ListNode("");

	LinkedList* expressLaneList;
	LinkedList* normalLaneList; 


	Queue expressLane; 
	Queue normalLane;

	int totalTime = 0, totalExpressLaneCustomersCheckedOut = 0, totalNormalLaneCustomersCheckedOut = 0;
	int expressLaneAverageWait = 0, normalLaneAverageWait = 0;
	int expressCustomerNumber = 0, normalCustomerNumber = 0;
	int expressLaneArrivalTime = 0, normalLaneArrivalTime = 0;
	int expressLaneServiceTime = 0, normalLaneServiceTime = 0;
	int expressLaneDepartureTime = 0, normalLaneDepartureTime = 0;
	bool acceptNewExpressArrival = true, acceptNewNormalArrival = true;
	int expressLaneNumberOfItems = 0, normalLaneNumberOfItems = 0;
	int randomItem = 0;
	int runTime = 0;

	//20 items
	string groceryItems[] = { "milk", "eggs", "steak", "chicken", "pork", "bacon", "cereal", "apples", "mangos", "blueberries", "strawberries", "soda", "cheese", "ranch", "oranges", "lettuce", "carrots", "creamer", "chips", "salsa" };

	cout << "Please enter the desired run time in minutes: ";
	cin >> runTime;

	for (int x = 0; x <= runTime; x++) { 

	//************************************************************************************************************************


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
			expressLaneNumberOfItems = rand() % 5 + 1;
			randomItem = rand() % 20 + 1;
			if (expressLaneNumberOfItems + randomItem > 20) {
				randomItem -= expressLaneNumberOfItems; 
			}
			expressLaneList = new LinkedList; 
			for (int y = 0; y < expressLaneNumberOfItems; y++) {
				expressLaneList->insertAtFront(groceryItems[randomItem + y]); 
			}
			expressCustomerNumber++; 
			expressLaneData = new Data(expressCustomerNumber, expressLaneNumberOfItems, x);
			expressLane.enqueue(expressLaneData, expressLaneList); 
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
				cout << "Time in Line: " << (x - returnedExpressLaneData->getpData()->getTotalTime()) << " " << "Groceries Bought: ";
				returnedExpressLaneData->getppHead()->printList();
				cout << endl; 
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
			normalLaneNumberOfItems = rand() % 8 + 1; 
			if (normalLaneNumberOfItems < 3) {
				normalLaneNumberOfItems = rand() % 8 + 1;
			}
			randomItem = rand() % 20 + 1;
			if (normalLaneNumberOfItems + randomItem > 20) {
				randomItem -= normalLaneNumberOfItems; 
			}
			normalLaneList = new LinkedList;
			for (int y = 0; y < normalLaneNumberOfItems; y++) { 
				normalLaneList->insertAtFront(groceryItems[randomItem + y]); 
			}

			normalCustomerNumber++;
			normalLaneData = new Data(normalCustomerNumber, normalLaneNumberOfItems, x);
			normalLane.enqueue(normalLaneData, normalLaneList); 
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
				cout << "Time in Line: " << (x - returnedNormalLaneData->getpData()->getTotalTime()) << " " << "Groceries Bought: ";
				returnedNormalLaneData->getppHead()->printList();
				cout << endl;
				totalNormalLaneCustomersCheckedOut += 1;
				normalLaneAverageWait += (x - returnedNormalLaneData->getpData()->getTotalTime()); 
				//cout << " " << "Total Time Esapsed: " << x << endl; 
				if (normalLane.getpTail() != nullptr) {
					normalLaneDepartureTime = x + normalLane.getpTail()->getpData()->getServiceTime();
				}
			}
		}




//**************************************************************************************************************************************



		if (x % 10 == 0) {
			cout << endl << "Total Time Esapsed: " << x << endl << "Express Lane: " << endl << "Back" << endl << "|" << endl;
			expressLane.printQueue();
			cout << "Front ^";
			cout << endl << endl; 
			cout << "Normal Lane: " << endl << "Back" << endl << "|" << endl;
			normalLane.printQueue();
			cout << "Front ^";
			cout << endl << endl; 
		}
	}

	cout << endl << endl << "Total Time Elapsed: " << runTime << endl; 
	expressLaneAverageWait = expressLaneAverageWait / totalExpressLaneCustomersCheckedOut; 
	cout << "Total Express Lane Customers Serviced: " << totalExpressLaneCustomersCheckedOut << endl;
	cout << "Express Lane Average Wait Time: " << expressLaneAverageWait << endl << endl;
	if (totalNormalLaneCustomersCheckedOut != 0) {
		normalLaneAverageWait = normalLaneAverageWait / totalNormalLaneCustomersCheckedOut;
		cout << endl << endl <<  "Total Normal Lane Customers Serviced: " << totalNormalLaneCustomersCheckedOut << endl;
		cout << "Normal Lane Average Wait Time: " << normalLaneAverageWait << endl << endl;
	}
	else if (totalNormalLaneCustomersCheckedOut == 0) {
		cout << endl << "No Customers checkout in the time frame!";
	}
	
}

void runLauncher(void)
{
	int option = 0;
	bool status = true;
	Launcher l;
	

	while (status == true) {
		cout << "Welcome to the Grocery Line Simulator!" << endl; 
		option = l.menu();
		switch (option) {
		case 1: runTestSuite();
			break;
		case 2: l.simulation();
			system("pause");
			system("cls");
			break;
		case 3:
			status = false;
			break;
		}
	}

}

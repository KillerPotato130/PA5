#include "Data.h"

Data::Data(const int newCustomerNumber, const int newServiceTime, const int newTotalTime) 
{
	this->customerNumber = newCustomerNumber;
	this->serviceTime = newServiceTime;
	this->totalTime = newTotalTime;
}








Data::Data(const Data& copy)
{
	customerNumber = copy.customerNumber;
	serviceTime = copy.serviceTime;
	totalTime = copy.totalTime; 
}

Data::~Data()
{
	   
} 

Data& Data::operator=(const Data& rhs)
{
	this->customerNumber = rhs.customerNumber;
	this->serviceTime = rhs.serviceTime;
	this->totalTime = rhs.serviceTime;

	return (*this); 

	// TODO: insert return statement here
}



int Data::getCustomerNumber()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}

void Data::setCustomerNumber(int newData)
{
	customerNumber = newData; 

}

void Data::setServiceTime(int newData)
{
	serviceTime = newData;
}

void Data::setTotalTime(int newData)
{
	totalTime = newData;
}

ostream& operator<<(ostream& os, const Data& output)
{
	os << "Customer Number: " << output.customerNumber << endl << "Service Time: " << output.serviceTime << endl << "Total Time: " << output.totalTime;

	return os;
}

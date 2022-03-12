#pragma once

#include <iostream>
#include <time.h>
#include <string>
#include <math.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ostream; 



class Data {

public: // Member functions
    Data(const int newCustomerNumber, const int newServiceTime, const int newTotalTime); 
  
    Data(const Data& copy); 
    ~Data(); 

    Data& operator= (const Data& rhs); 
    friend ostream&  operator<< (ostream& os, const Data& output);   

    int getCustomerNumber();
    int getServiceTime();
    int getTotalTime();

    void setCustomerNumber(int newData);
    void setServiceTime(int newData);
    void setTotalTime(int newData);


private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!
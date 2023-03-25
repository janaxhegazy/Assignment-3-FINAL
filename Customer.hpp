//
//  Customer.hpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#ifndef Customer_hpp
#define Customer_hpp
#include<iostream>
#include<string>
#include"Person.hpp"
using namespace std;

class Customer : public person
{
private:
    int MechanicID;
    Appointment app;
public:
    Customer();
    Customer(string, Appointment);
    Customer(string, int, int, int, Appointment);
    
    virtual void PrintInfo() const;
   
    bool operator>(const Customer&) const;
    bool operator==(const Customer&) const;
    bool operator<(const Customer&) const;
    
    void setMID(int);
    void setApp(Appointment);
    int getMID() const;
    Appointment getApp() const;

};
#endif /* Customer_hpp */




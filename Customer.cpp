//
//  Customer.cpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#include<iostream>
#include<string>
using namespace std;
#include "Customer.hpp"
Customer::Customer() : person()
{
   
    this->MechanicID = 0;
    this->app.hours = -1;
    this->app.mins = -1;
}
Customer::Customer(string str, Appointment moment) :  Customer(str, 0, 0, 0, moment)
{


}
Customer::Customer(string nam,int id, int ag, int mid, Appointment temp): person(nam,id,ag)
{
    
    this->MechanicID = mid;
    this->app = temp;
}
void Customer::PrintInfo() const
{
    cout << "customer's name is " << this->getName() << endl;
    cout << "age is " << this->getAge() << endl;
    cout << "ID is " << this->getID() << endl;
    if (this->getApp().hours == -1)
        cout << "Sorry, but no mechanaic avaliable at this time. CHECK AT ANY OTHER SLOT. " << endl<<endl;
    else
    {
        cout << "this customer has an Appointment at " << this->getApp().hours << ":" << this->getApp().mins <<endl;
        cout << " and they are assigned to mechanic " << this->getMID() << endl<<endl;
    }
}
void Customer::setMID(int id)
{
    this->MechanicID = id;
}
void Customer::setApp(Appointment test)
{
    this->app = test;
}
int Customer::getMID() const
{
    return this->MechanicID;
}
Appointment Customer::getApp() const
{
    return this->app;
}
bool Customer::operator<(const Customer &compare) const
{
    if (this->getApp().hours < compare.getApp().hours)
    {
        return true;
    }
    else if (this->getApp().hours > compare.getApp().hours)
    {
        return false;
    }
    else if (this->getApp().mins >= compare.getApp().mins)
    {
        return false;
    }
    else if (this->getApp().mins <= compare.getApp().mins)
    {
        return true;
    }
    return true;
}
bool Customer::operator>(const Customer &compare) const
{
    if ((*this < compare) || ((this->getApp().hours == compare.getApp().hours) && (this->getApp().mins == compare.getApp().mins)))
        return false;
    else
        return true;
}
bool Customer::operator==(const Customer &compare) const
{
    if ((this->getApp().hours == compare.getApp().hours) && (this->getApp().mins == compare.getApp().mins))
        return true;
    else
        return false;
}

//
//  Mechanics.hpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#ifndef Mechanics_hpp
#define Mechanics_hpp
#include "Person.hpp"
#include <iostream>


using namespace std;

class Mechanic : public person
{
private:
    int counter;
    Appointment* appoints;
public:
    Mechanic();
    Mechanic(string, int, int);
    void printInfo() const;
    bool IsAvailable(Appointment) const;
    
    void setCount(int);
    void setApp(Appointment);
    int getCounter() const;
    Appointment getApp(int) const;
};

#endif /* Mechanics_hpp */

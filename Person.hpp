//
//  Person.hpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#ifndef Person_hpp
#define Person_hpp
#include <iostream>
using namespace std;

struct Appointment
{
    int hours;
    int mins;
    Appointment()
    {
        hours = 0;
        mins = 0;
    }
    Appointment(int h, int m)
    {
        if (h < 0 || h>23)
            hours = -1;
        else
            hours = h;

        if (m < 0 || m>59)
            mins = -1;
        else
            mins = m;

    }
    void printAppoint()
    {
        cout << hours << ":" << mins << endl;
    }
};

class person {
private:
    string name;
    int ID, age;
public:
    person();
    person(string, int, int );
    void setName(string);
    void setID(int);
    void setAge(int);
    string getName() const;
    int getID() const;
    int getAge() const;
    virtual void printInfo() const = 0;
    
};
#endif /* Person_hpp */

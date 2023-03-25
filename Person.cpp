//
//  Person.cpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//
#include "Person.hpp"
#include <iostream>
using namespace std;

person::person() {
    
}
person:: person(string s,int i,int x) {
    name = s;
    ID = i;
    age = x;
}
void person::setID(int s)
{
    ID = s;
}
void person::setAge(int x)
{
    age = x;
}
void person::setName(string n)
{
    name = n;
}
int person::getAge() const
{
    return age;
}
int person::getID() const
{
    return ID;
}
string person::getName() const
{
    return name;
}



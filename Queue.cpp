//
//  Queue.cpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#include "Queue.hpp"
#include<iostream>
using namespace std;
template<class T>
Queue<T>::Queue()
{
    front = -1;
    rear = -1;
    count = 0;
    MAXsize = 10;
    arr = new T[MAXsize];
}
template<class T>
Queue<T>::Queue(int x)
{
    MAXsize = x;
    arr = new T[MAXsize];
    front = -1;
    rear = -1;
    count = 0;
   
}
template<class T>
Queue<T>::~Queue()
{
    delete[]arr;
}
template<class T>
bool Queue<T>::isEmpty() const
{
    if (getCount() == 0)
        return 1;
    else
        return 0;
}
template<class T>
bool Queue<T>::isFull() const
{
    if (getCount() == (getSize() - 1))
        return 1;
    else
        return 0;
}

template<class T>
int Queue<T>::getCount() const
{
    return count;
}
template<class T>
int Queue<T>::getSize() const
{
    return MAXsize;
}

template<class T>
T Queue<T>::pop()
{
    if (!isEmpty())
    {
        return arr[front++];
       front %= getSize();
        count--;
    }
    else
        cout << "EMPTY!!" << endl;
    return 0;
}
template<class T>
void Queue<T>::push(T temp)
{
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[0] = temp;
        count++;
    }
    if (!isFull())
    {
       this->arr[++rear%this->getSize] = temp;
        rear %= getSize();
        count++;
    }
    else
        cout << "FULL!!" << endl;
}


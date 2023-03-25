//
//  Queue.hpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.
//

#ifndef Queue_hpp
#define Queue_hpp

template<class T>
class Queue
{
private:
    T* arr;
    int MAXsize;
    int front;
    int rear;
    int count;
   

public:
    Queue() ;
    Queue(int);
    ~Queue();
  
    void push(T);
    T pop();
    int getCount() const;
    int getSize() const;
    
    bool isEmpty() const;
    bool isFull() const;
};


#endif /* Queue_hpp */

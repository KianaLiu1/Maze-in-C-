#ifndef queue_h
#define queue_h

#define MAX 1000

#include "Cell.h"
#include <iostream>

using namespace std;


class queue
{
private:
    int front;
    int back;
    cell array[MAX];
public:
    void CreateQueue();
    void PushQueue(cell a);
    cell PopQueue();
    bool EmptyQueue();
    void PrintQueue();
    cell peak();
    //bool FullQueue();
};

void queue::CreateQueue()
{
    front = -1;
    back = -1;
}

void queue::PushQueue(cell a)
{
    back++;
    array[back]=a;
    
    if(front==-1)
        front=0;
    
}

cell queue::PopQueue()
{
    cell c;
    c=array[front];

    if(front==back)
    {
        front=-1;
        back=-1;
    }
    else   front++;
    return c;
}

bool queue::EmptyQueue()
{
    if(back==-1)
        return true;
    else return false;
        
}

void queue::PrintQueue()
{
    if(EmptyQueue()==false)
    {
        for(int i=front; i<=back; i++)
        {
            cout<<array[i].GetNumber()<<endl;
        }

    }
    else
        cout<<"This queue is empty";
}

cell queue::peak()
{
    return array[front];
}




#endif /* queue_h */

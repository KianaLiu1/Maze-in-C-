
#ifndef stack_h
#define stack_h
#define MAX 1000

#include "Cell.h"
#include <iostream>

using namespace std;

class stack
{
private:
    int CurrentCell;
    cell array[MAX];
public:
    void CreateStack();
    void PushStack(cell a);
    cell PopStack();
    bool FullStack();
    bool EmptyStack();
    void PrintStack();
    cell peak();
    
};

void stack::CreateStack()
{
    CurrentCell = -1;
}

void stack::PushStack(cell a)
{
    CurrentCell++;
    array[CurrentCell]=a;
    
}
cell stack::PopStack()
{
    cell c = array[CurrentCell];
    CurrentCell--;
    return c;
}

bool stack::FullStack()
{
    if(CurrentCell == MAX-1)
    {
        return true;
    }
    else return false;
}

bool stack::EmptyStack()
{
    if(CurrentCell == -1)
    {
        return true;
    }
    else return false;
}

void stack::PrintStack()
{
    cout<<"Print stack"<<endl;
    for(int i=0; i<=CurrentCell;i++)
    {
        cout<<array[i].GetNumber()<<endl;
    }
}

//check the top of the stack
cell stack::peak()
{
    cell c = array[CurrentCell];
    return c;
}


#endif /* stack_h */


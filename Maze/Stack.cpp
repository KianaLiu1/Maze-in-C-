//
//  Stack.cpp
//  Maze
//
//  Created by Kiana Liu on 6/6/18.
//  Copyright © 2018 Kiana LIU. All rights reserved.
//

#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    cell cell1;
    cell cell2;
    
    cell1.SetNumber(1);
    cell2.SetNumber(2);

    stack Stack;
    Stack.CreateStack();
    
    if(Stack.EmptyStack()==true)
        cout<<"The stack is empty."<<endl;
    
    Stack.PushStack(cell1);
    Stack.PushStack(cell2);
    
    Stack.PrintStack();
    
    Stack.PopStack();
    
    Stack.PrintStack();

}

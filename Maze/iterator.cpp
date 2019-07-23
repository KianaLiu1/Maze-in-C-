//
//  iterator.cpp
//  Maze
//
//  Created by Kiana Liu on 13/6/18.
//  Copyright © 2018 Kiana LIU. All rights reserved.
//

#include "iterator.h"
#include <iostream>

using namespace std;

int main()
{
    path path1;
    cell cell1, cell2;
    
    cell1.SetNumber(1);
    cell2.SetNumber(2);
    
    path1.add(cell1);
    path1.add(cell2);
    
    cout<<path1.GetSize();
    /*for(int i=0; i<path1.GetSize(); i++)
        cout<<*/
    
}

//
//  list.h
//  Maze
//
//  Created by Kiana Liu on 18/6/18.
//  Copyright © 2018 Kiana LIU. All rights reserved.
//

#ifndef list_h
#define list_h

class neighbour
{
private:
    int row,  column, wall;
public:
    
    void SetRow(int x)
    {
        row = x;
    }
    void SetColumn(int y)
    {
        column = y;
    }
    int GetRow()
    {
        return row;
    }
    int GetColumn()
    {
        return column;
    }
    void SetWall(int a)
    {
        wall = a;
    }
    int GetVisit()
    {
        return wall;
    }
    
    
};


#endif /* list_h */

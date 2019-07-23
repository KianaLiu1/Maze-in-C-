#ifndef Cell_h
#define Cell_h

#include "list.h"

//create a class contains all the cells
class cell
{
private:
    int number, row, column, NeighbourNumber;
    bool visitStatus;
    int PathCheck=-1;
    neighbour* NeighbourList = new neighbour[4];
public:

    void SetRow(int x)
    {
        row = x;
    }
    void SetColumn(int y)
    {
        column = y;
    }
    void SetNumber(int m)
    {
        number = m;
    }
    int GetNumber()
    {
        return number;
    }
    int GetRow()
    {
        return row;
    }
    int GetColumn()
    {
        return column;
    }
    void SetVisit(bool a)
    {
        visitStatus = a;
    }
    bool GetVisit()
    {
        return visitStatus;
    }
    void SetNeighbour(int z)
    {
        NeighbourNumber = z;
    }
    int GetNeighbour()
    {
        return NeighbourNumber;
    }
    neighbour* GetNeighbourList()
    {
        return NeighbourList;
    }
    void OnPath(int a)
    {
        PathCheck=a;
    }
    int CheckPath()
    {
        return PathCheck;
    }
    
};

#endif /* Cell_h */

#include "Cell.h"
#include <iostream>
using namespace std;

int main()
{
    cell cell1;
    cell1.SetRow(2);
    cell1.SetColumn(3);
    cell1.SetVisit(false);
    
    cout<<cell1.GetColumn()<<endl;
    cout<<cell1.GetRow()<<endl;
    cout<<cell1.GetVisit()<<endl;
    
}

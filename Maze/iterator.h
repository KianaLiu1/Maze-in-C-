
#ifndef iterator_h
#define iterator_h
#include "Cell.h"
#include <vector>

using namespace std;

class path
{
private:
    vector<cell> p;
public:
    bool empty();
    int GetSize();
    void clear();
    void add(cell a);
    void Print();
};

bool path::empty()
{
    if(p.size()==0)
        return true;
    else
        return false;
}

int path::GetSize()
{
    return p.size();
}

void path::clear()
{
    p.clear();
}

void path::add(cell a)
{
    p.push_back(a);
}

/*void path::Print()
{
    for(int i=0; i<p.size(); i++)
        cout<<p.at(i).GetNumber()<<endl;
}*/


#endif /* iterator_h */

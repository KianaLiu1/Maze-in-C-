#include "queue.h"

using namespace std;

int main()
{
    queue Q;
    
    cell c1, c2;
    c1.SetNumber(1);
    c2.SetNumber(2);
    
    Q.CreateQueue();
    Q.PushQueue(c1);
    Q.PushQueue(c2);
    
    Q.PrintQueue();
    Q.PopQueue();
    Q.PrintQueue();
    Q.PopQueue();
    Q.PrintQueue();
    
    
}

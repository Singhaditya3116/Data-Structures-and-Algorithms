#include<bits/stdc++.h>
#include "priorityQueue.h"
using namespace std;

int main()
{
    PriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);


    cout <<p.getSize()<<endl;
    cout <<"Min Value "<<p.getMin()<<endl;

    while(p.isEmpty() == false)
    {
        cout <<p.removeMin()<<" ";
    }

    return 0;
}

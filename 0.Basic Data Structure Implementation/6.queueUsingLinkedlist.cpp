#include<iostream>
#include "6.queueUsingLinkedlist.h"

using namespace std;

int main()
{
    queueUsingLinkedlist<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout <<"size "<<q.getSize()<<endl;
    cout <<q.front()<<endl;
    q.dequeue();
    cout <<"size "<<q.getSize()<<endl;
    cout <<q.front()<<endl;
    cout <<q.isEmpty()<<endl;

    return 0;
}

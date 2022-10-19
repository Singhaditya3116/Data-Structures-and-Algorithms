#include<iostream>

using namespace std;
#include "5.queueUsingArray.h"

int main()
{
    queueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout <<q.getfront()<<endl;
    q.dequeue();
    cout <<q.getfront()<<endl;
    cout <<q.isEmpty()<<endl;


    return 0;
}

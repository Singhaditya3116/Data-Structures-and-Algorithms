#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(20);
    pq.push(10);
    pq.push(1);
    pq.push(5);
    pq.push(56);

    cout <<pq.size()<<endl;
    cout <<pq.empty()<<endl;

    while(pq.size() != 0)
    {
        cout <<pq.top()<<" ";
        pq.pop();
    }
    cout <<endl;


    return 0;
}

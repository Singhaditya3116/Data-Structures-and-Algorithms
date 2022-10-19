#include<bits/stdc++.h>
using namespace std;

void createBST(int finalLevel)
{
    int size=pow(2,finalLevel);
    //Node *Address[size]={0};
    int data[size]={0};

    queue <int> q;
    q.push(finalLevel);
    int level=1,i=1;
    data[i]=finalLevel;
    i++;
    while(q.size()!=0)
    {
        int value=q.front();
        q.pop();
        int distinct_node=pow(2,finalLevel-level);
        if(distinct_node >2)
        {

        }
    }

}


int main()
{
    int level;
    cin >> level;
    createBST(level);
    return 0;
}

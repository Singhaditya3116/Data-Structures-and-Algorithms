#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int meat[n],cost[n];
    for(int i=0;i<n;i++)
    {
        cin >> meat[i] >>cost[i];
    }

    int totalMoney=meat[0]*cost[0];

    int mincost=cost[0];
    for(int i=1;i<n;i++)
    {
        if(cost[i] >= mincost)
        {
            totalMoney+=(mincost*meat[i]);
        }
        else
        {
            mincost=cost[i];
            totalMoney+=meat[i]*cost[i];
        }
    }

    cout <<totalMoney<<endl;
    return 0;
}

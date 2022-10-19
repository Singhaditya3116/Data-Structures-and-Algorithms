#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,mvalue;
        cin >> n >> mvalue;
        int fruitType[n];
        int cost[n]={0};

        for(int i=0;i<n;i++)
        {
            cin >> fruitType[i];
        }

        for(int i=0;i<n;i++)
        {
            cin >> cost[i];
        }

        map<int,int> m;

        for(int i=0;i<n;i++)
        {
            m[fruitType[i]]+=cost[i];
        }

        map<int,int> :: iterator it;
        int min = INT_MAX;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second < min)
            {
                min = it->second;
            }
        }
        cout << min <<endl;
    }
    return 0;
}

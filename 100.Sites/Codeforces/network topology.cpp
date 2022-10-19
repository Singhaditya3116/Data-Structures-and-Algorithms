#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    int degree[nodes];
    for(int i=0;i<nodes;i++)
    {
        degree[i]=0;
    }
    while(edges--)
    {
        int start,end;
        cin >> start >>end;
        start--;end--;
        degree[start]++;
        degree[end]++;
    }

    bool buscheck=false,ringcheck =false;
    int onecount=0,twocount=0,specialCount=0;
    for(int i=0;i<nodes;i++)
    {
        if(degree[i]==1)
            onecount++;
        if(degree[i]==2)
            twocount++;
        if(degree[i]==nodes-1)
            specialCount++;
    }
    if(onecount == 2 && twocount ==nodes-2)
    {
        cout << "bus topology"<<endl;
    }else if(twocount == nodes)
            {
                cout << "ring topology"<<endl;
            }else if(onecount == nodes-1 && specialCount ==1)
                    {
                        cout << "star topology" <<endl;
                    }else
                    {
                        cout << "unknown topology" <<endl;
                    }

    return 0;
}


#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int vertex,edges;
        cin >> vertex >> edges;
        int sum=0;
        int cost[vertex];
        int smallfirst=INT_MAX;int smallsecond=INT_MAX;
        int index1=0,index2=0;
        for(int i=0;i<vertex;i++)
        {
            cin >> cost[i];
            int value = cost[i];
            sum+=value;
            if(value < smallfirst)
            {
                smallsecond=smallfirst;
                index2=index1;
                smallfirst=value;
                index1=i;
            }
            else
            {
                if(value >= smallfirst && value < smallsecond)
                {
                    smallsecond=value;
                    index2=i;
                }
            }
        }
        if(vertex == 2)
        {
            cout <<"-1" <<endl;
            continue;
        }

        int mindegree = 2*vertex;
        int currdegree = 2*edges;
        if(currdegree < mindegree)
        {
            cout << "-1" <<endl;
        }
        else
        {
            int ans = 2*sum;
            int extraedge = edges-vertex;
            while(extraedge--)
            {
                ans +=(smallfirst + smallsecond);
            }

            cout << ans <<endl;
            for(int i=0;i<vertex-1;i++)
            {
                cout << i+1 <<" " <<i+2<<endl;
            }
            cout << vertex <<" " << "1" <<endl;

            extraedge=edges-vertex;
            while(extraedge--)
            {
                cout <<index1 +1 <<" " <<index2+1<<endl;
            }
        }
    }

    return 0;
}

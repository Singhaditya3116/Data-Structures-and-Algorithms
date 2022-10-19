#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(vector<int> *graph,int vertices,int start,bool *visited,ll *cost,ll &mincost)
{
    visited[start]=true;
    if(mincost > cost[start])
    {
        mincost = cost[start];
    }

    for(int i=0;i<graph[start].size();i++)
    {
        int adj=graph[start][i];
        if(visited[adj]==false)
        {
            dfs(graph,vertices,adj,visited,cost,mincost);
        }
    }
}



int main()
{
    int vertices,edges;
    cin >>vertices >>edges;
    vector<int> graph[vertices];
    ll cost[vertices];
    for(int i=0;i<vertices;i++)
    {
        cin >> cost[i];
    }
    while(edges--)
    {
        int fv,sv;
        cin >> fv >>sv;
        fv--;sv--;
        graph[fv].push_back(sv);
        graph[sv].push_back(fv);
    }

    bool visited[vertices];
    memset(visited,false,sizeof(visited));

    ll finalCost=0;
    for(int i=0;i<vertices;i++)
    {
        if(visited[i]==false)
        {
            ll mincost = cost[i];
            dfs(graph,vertices,i,visited,cost,mincost);
            finalCost+=mincost;
        }
    }
    cout << finalCost <<endl;
    return 0;

}


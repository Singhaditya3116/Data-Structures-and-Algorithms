#include<bits/stdc++.h>
using namespace std;

void dfs(int **graph,int n,int start,bool *visited)
{
    visited[start]=true;
    for(int i=0;i<n;i++)
    {
        if(graph[start][i]==1 && !visited[i])
        {
            dfs(graph,n,i,visited);
        }
    }
}


int main()
{
    int n,e;
    cin >> n >> e;
    int **graph = new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    while(e--)
    {
        int fv,sv;
        cin >> fv >> sv;
        fv--;sv--;
        graph[fv][sv]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int extrawork=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            extrawork++;
            dfs(graph,n,i,visited);
        }
    }
    cout << extrawork <<endl;

    return 0;
}

#include<iostream>
#include<bits/stdc++.h>
#include<utility>
using namespace std;

void dfs(int **graph,int curr,bool *visited,int n,int &end,int &mincost)
{
    cout <<curr <<" ";
    visited[curr]=true;
    end=curr;
    for(int j=0;j<n;j++)
    {
        if(visited[j]==false && graph[curr][j]>=1)
        {
            mincost=min(mincost,graph[curr][j]);
            dfs(graph,j,visited,n,end,mincost);
        }
    }
}

bool isIncoming(int **graph,int index,int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[i][index]>=1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int house,pipe;
    cin >> house >>pipe;
    int **graph = new int*[house];
    for(int i=0;i<house;i++)
    {
        graph[i]=new int[house];
        for(int j=0;j<house;j++)
        {
            graph[i][j]=0;
        }
    }
    while(pipe--)
    {
        int first,second,weight;
        cin >> first ;
        cin >>second;
        cin >>weight;
        first--;second--;
        graph[first][second]=weight;
    }

    bool visited[house];
    for(int i=0;i<house;i++)
    {
        visited[i]=false;
    }
    vector < pair<int,int> > connection;
    vector<int> cost;
    int k=0;

    for(int i=0;i<house;i++)
    {
        cout <<"kochi "<<i<<endl;
        int end=-1;
        int mincost=-1;
        if((visited[i]==false) && isIncoming(graph,i,house))
        {
            dfs(graph,i,visited,house,end,mincost);
            if(end!= -1 )
            {
                connection[k].first=i;
                connection[k].second=end;
                //cost[k]=mincost;
                k++;
            }
            cout <<endl;
        }
    }



    cout <<connection.size()<<endl;
    for(int i=0;i<connection.size();i++)
    {
        cout <<connection[i].first <<" " <<connection[i].second<<" " <<cost[i];
        cout <<endl;
    }

    return 0;
}

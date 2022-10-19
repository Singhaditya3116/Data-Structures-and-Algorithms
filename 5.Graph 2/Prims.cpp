#include<bits/stdc++.h>
#define endl "\n";
using namespace std;

bool isVisited(bool *visited,int v)
{
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            return false;
        }
    }
    return true;
}

void Prims(int **graph,int *parent,int *weight,bool *visited,int vertex)
{
    while(!isVisited(visited,vertex))
    {
        int minweight=INT_MAX;
        int vindex=0;
        for(int i=0;i<vertex;i++)
        {
            if(weight[i] < minweight && visited[i] == false)
            {
                minweight=weight[i];
                vindex=i;
            }
        }
        visited[vindex]=true;
        for(int j=0;j<vertex;j++)
        {
            if(graph[vindex][j]>0 && visited[j]==false)
            {
                int currweight=graph[vindex][j];
                if(currweight < weight[j])
                {
                    weight[j]=currweight;
                    parent[j]=vindex;
                }
            }
        }
    }
}

int main()
{
    int v,e;
    cin >> v >>e;
    int **graph = new int*[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int first,second,cost;
        cin >> first >> second >> cost;
        graph[first][second]=cost;
        graph[second][first]=cost;
    }

    int parent[v],weight[v];\
	bool visited[v];
    for(int i=0;i<v;i++)
    {
        weight[i]=INT_MAX;
        parent[i]=-1;
        visited[i]=false;
    }
    parent[0]=0;
    weight[0]=0;

    Prims(graph,parent,weight,visited,v);

    for(int i=1;i<v;i++)
    {
        if(i < parent[i])
        {
        	cout << i << " " << parent[i] << " " << weight[i] <<endl;
        }
        else
        {
            cout << parent[i] << " "<< i << " "<< weight[i] <<endl;
        }
    }

}

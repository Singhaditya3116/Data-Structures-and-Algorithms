#include<bits/stdc++.h>
using namespace std;

void dfs(int **graph,int start,bool *visited,int n)
{
    visited[start]=true;
    for(int i=1;i<=n;i++)
    {
        if(graph[start][i]==1 && !visited[i])
        {
            dfs(graph,i,visited,n);
        }
    }
}


bool isPath(int **graph,int v1,int v2,int n)
{
    bool visited[n+1];
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    dfs(graph,v1,visited,n);
    //cout <<"visi" <<visited[v1] << " " <<visited[v2] <<endl;
    if(visited[v2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findIndex(int value,int *arr,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
}


int findMinute(int *arr,int n,int **graph)
{
    int minute=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==i)
        {
            continue;
        }
        int index=findIndex(i,arr,n);
        int temp = arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
        if(isPath(graph,i,index,n)==false)
        {
            graph[i][index]=1;
            graph[index][i]=1;
            minute+=1;
        }
    }
    return minute;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,m;
        cin >> n >>m;
        int arr[n+1];
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i];
        }
        int **graph = new int*[n+1];
        for(int i=1;i<=n;i++)
        {
            graph[i]=new int[n+1];
            for(int j=0;j<=n;j++)
            {
                graph[i][j]=0;
            }
        }
        while(m--)
        {
            int fv,sv;
            cin >> fv >>sv;
            graph[fv][sv]=1;
            graph[sv][fv]=1;
        }

        cout << findMinute(arr,n,graph) <<endl;
    }

    return 0;
}

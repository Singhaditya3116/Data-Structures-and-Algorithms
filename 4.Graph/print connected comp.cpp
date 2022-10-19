#include<bits/stdc++.h>

using namespace std;

void print(int** edges,int n,int startvertex,bool* visited)
{
    visited[startvertex]=true;
    for(int i=0;i<n;i++)
    {

        if(edges[startvertex][i]==1)
        {
            if(!visited[i])
            {
            print(edges,n,i,visited);
            }
        }
    }
}


int isallvisited(bool* visited,int n)
{
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                return 1;
            }
        }
        return 0;
}

int main()
{
    int n  ;//NO. of Vertices
    int e;
    cin >> n >> e ;

    int **edges =new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    int s,f;
    while(e!=0)
    {
        cin >> f >>s;
        edges[s][f]=1;
        edges[f][s]=1;
        e--;
    }

    bool* visited =new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    int store=0;
    while(isallvisited(visited,n))
    {
        print(edges,n,store,visited);
         for(int i=0;i<n;i++)
        {
            if(visited[i]==true)
            {
                cout << i <<" ";
            }
        }

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                store=i;
                break;
            }
         }
        for(int i=0;i<n;i++)
        {
        visited[i]=false;
        }
        cout<<endl;
    }


}

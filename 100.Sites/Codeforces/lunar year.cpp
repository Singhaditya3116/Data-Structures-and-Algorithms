#include<bits/stdc++.h>

using namespace std;

void print(int** edges,int n,int startvertex,bool* visited)
{
    cout << startvertex+1 <<" ";
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
        f--;s--;
        edges[s][f]=1;
        edges[f][s]=1;
        e--;
    }

    bool* visited =new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);

}

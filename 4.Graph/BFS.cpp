#include<bits/stdc++.h>
#include<queue>
using namespace std;

 void print(int** edges,int V,int startvertex,bool* visited)
{
    int popelement;
    queue <int> q;
    q.push(startvertex);
    visited[startvertex]=true;

    while(!q.empty())
    {

        popelement=q.front();
        q.pop();
        cout <<popelement<<endl;
        for(int i=0;i<V;i++)
        {
            if(edges[popelement][i]==1)
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

}

int main()
{
    int V,E;
    cin >>V >>E;

    int** edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }

    int f,s;
    while(E!=0)
    {
        cin >> f >>s;
        edges[f][s]=1;
        edges[s][f]=1;
        E--;
    }

    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    print(edges,V,0,visited);

    for(int i=0;i<V;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;


    return 0;
}

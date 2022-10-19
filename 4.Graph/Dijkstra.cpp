#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int** edgestore,int* distance,bool* visited,int V);
int main()
{
  int V, E;
  cin >> V >> E;


    int** edgestore = new int*[V];//creating an adjacent matrix
    for(int i=0;i<V;i++)
    {
        edgestore[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edgestore[i][j]=0;
        }
    }
    while(E!=0)//taking input equal to no. of edges in adjacency matrix
    {
        int startvertex,endvertex,dist;
        cin >>startvertex>>endvertex>>dist;
        edgestore[startvertex][endvertex]=dist;
        edgestore[endvertex][startvertex]=dist;
        E--;
    }

    int* distance=new int[V];
    for(int i=1;i<V;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[0]=0;

    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    Dijkstra(edgestore,distance,visited,V);

    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }

  return 0;
}

bool isvisited(bool* visited,int V)
{
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            return true;
        }
        return false;
    }
}


void Dijkstra(int** edgestore,int* distance,bool* visited,int V)
{
    int mindistance=INT_MAX;
    int mindistancevertex;

while(isvisited(visited,V))
{
    mindistance=INT_MAX;
    for(int i=0;i<V;i++)
    {
        cout<<"hello"<<endl;
        if(distance[i]<mindistance && !visited[i])
        {
            mindistance=distance[i];
            mindistancevertex=i;
        }
    }

    visited[mindistancevertex]=true;

    for(int adjacent=0;adjacent<V;adjacent++)
    {
        cout<<"world";
        if(edgestore[mindistancevertex][adjacent]>0 && !visited[adjacent])
        {
            if(distance[adjacent]>(distance[mindistancevertex]+edgestore[mindistancevertex][adjacent]))
            {
                distance[adjacent]=(distance[mindistancevertex]+edgestore[mindistancevertex][adjacent]);
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<" "<<distance[i];
    }
    cout<<endl;
}

}







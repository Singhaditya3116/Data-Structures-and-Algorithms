#include <bits/stdc++.h>
using namespace std;
void Prims(int** edgestore,int* parent,int* weight,bool* visited,int V);

int checkvisited(bool* visited,int V)//check::if any vertex is not visited
{
    for(int i=0;i<V;i++)
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
        int startvertex,endvertex,weight;
        cin >>startvertex>>endvertex>>weight;
        edgestore[startvertex][endvertex]=weight;
        edgestore[endvertex][startvertex]=weight;
        E--;
    }

    int* parent=new int[V];//a parent array
    for(int i=1;i<V;i++)
    {
        parent[i]=0;
    }
    parent[0]=-1;

    int* weight =new int[V];//weight of each vertex
    for(int i=1;i<V;i++)
    {
        weight[i]=INT_MAX;
    }
    weight[0]=0;

    bool* visited=new bool[V];//taking care of visited and unvisted vertex
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    Prims(edgestore,parent,weight,visited,V);

    for(int i=1;i<V;i++)//printing output
    {
        if(i<parent[i])
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }

  return 0;
}



void Prims(int** edgestore,int* parent,int* weight,bool* visited,int V)
{
    int minweight=INT_MAX;
    int vertexstore;
    while(checkvisited(visited,V))//run this loop until every veretx get visited
     {
        minweight=INT_MAX;
        for(int i=0;i<V;i++)//computing the vertex which has minimum weight
        {
            if(visited[i]==false&&weight[i]<minweight)
            {
                minweight=weight[i];
                vertexstore=i;
            }
        }

        visited[vertexstore]=true;
         for(int j=0;j<V;j++)//to compute adjacent and do minimum weight operation
         {
            if(edgestore[vertexstore][j]>0&&!visited[j])
             {
                if(edgestore[vertexstore][j]<weight[j])
                {
                    weight[j]=edgestore[vertexstore][j];
                    parent[j]=vertexstore;
                }
              }
          }

     }

}

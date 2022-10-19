#include<bits/stdc++.h>
using namespace std;
//-----------------------------Dijkstra algorithm only
void shortestPath(vector<int> *graph,int v,int *weight,bool *visited)
{
    int count=0;
    while(count != v)
    {
        int minVertex=0;
    	int minDistance=INT_MAX;
        for(int i=0;i<v;i++)     //computing minimum distNCE VERTEX
        {
            if(weight[i] < minDistance && visited[i]==false)
            {
                minVertex=i;
                minDistance=weight[i];
            }
        }
        visited[minVertex]=true;

        for(int i=0;i<graph[minVertex].size();i++) // finding adjacent and updating the distamce
        {
            int adj = graph[minVertex][i];
            if(visited[adj] == false)
            {
                if((weight[minVertex] + 1) < weight[adj])
                {
                    weight[adj]=(weight[minVertex] + 1);
                }

            }

        }
        count++;
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int v,e;
        cin >> v >>e;
        vector<int> graph[v];  //adjacency list
        while(e--)
        {
            int fv,sv;
            cin >> fv >>sv;
            fv--;sv--;
            graph[fv].push_back(sv);
            graph[sv].push_back(fv);
        }
        int weight[v];
        bool visited[v];
        for(int i=0;i<v;i++)
        {
            weight[i]=INT_MAX;
            visited[i]=false;
        }
        weight[0]=0;

        shortestPath(graph,v,weight,visited);
        cout <<weight[v-1] <<endl;
    }

	return 0;
}

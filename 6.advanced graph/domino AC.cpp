#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *graph,int n,int start, bool *visited,stack <int> &s)
{
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        int adj = graph[start][i];
        if(!visited[adj])
        {
            dfs(graph,n,adj,visited,s);
        }
    }
    s.push(start);
}

void dfs2(vector<int> *graph,int start,int n,bool *visited)
{
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        int adj = graph[start][i];
        if(!visited[adj])
        {
            dfs2(graph,adj,n,visited);
        }
    }
}


int kosaRaju(vector<int> *graph,vector<int> *graphT,int vertices)
{
    stack <int> st;

    bool *visited= new bool[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<vertices;i++)
    {
        if(visited[i]==false)
        {
            dfs(graph,vertices,i,visited,st);
        }
    }
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }
    int workDone=0;
    while(st.size()!=0)
    {
        int value = st.top();
        st.pop();
        if(visited[value] == false)
        {
            workDone++;
        	dfs2(graph,value,vertices,visited);
        }
    }
    return workDone;
}


int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int vertices,edges;
        cin >> vertices >> edges;

        vector<int> graph[vertices];
        vector<int> graphT[vertices];


        while(edges--)
        {
            int fv,sv;
            cin >> fv >> sv;
            fv--;sv--;
            graph[fv].push_back(sv);
            graphT[sv].push_back(fv);
        }


        cout << kosaRaju(graph,graphT,vertices) <<endl;
    }

    return 0;
}

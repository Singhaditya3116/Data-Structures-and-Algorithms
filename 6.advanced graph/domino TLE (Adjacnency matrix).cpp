#include<bits/stdc++.h>
using namespace std;

void dfs(int **graph,int n,int start, bool *visited,stack <int> &s)
{
    visited[start]=true;
    for(int i=0;i<n;i++)
    {
        if(graph[start][i]==1 && !visited[i])
        {
            dfs(graph,n,i,visited,s);
        }
    }
    s.push(start);
}

void dfs2(int **graphT,int start,int n,bool *visited,set<int> &innerset)
{
    visited[start]=true;
    innerset.insert(start);
    for(int i=0;i<n;i++)
    {
        if(graphT[start][i]==1 && !visited[i])
        {
            dfs2(graphT,i,n,visited,innerset);
        }
    }
}


void kosaRaju(int **graph,int **graphT,int vertices,set< set<int> > &s)
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

    while(st.size()!=0)
    {
        int value = st.top();
        st.pop();
        if(visited[value] == false)
        {
            set<int> innerset;
        	dfs2(graphT,value,vertices,visited,innerset);
    		s.insert(innerset);
        }

    }
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int vertices,edges;
        cin >> vertices >> edges;

        int **graph = new int*[vertices];
        int ** graphT = new int*[vertices];
        for(int i=0;i<vertices;i++)
        {
            graph[i]=new int[vertices];
            graphT[i]=new int[vertices];
            for(int j=0;j<vertices;j++)
            {
                graph[i][j]=0;
                graphT[i][j]=0;
            }
        }

        while(edges--)
        {
            int fv,sv;
            cin >> fv >> sv;
            fv--;sv--;
            graph[fv][sv]=1;
            graphT[sv][fv]=1;
        }

        set< set<int> > s;

        kosaRaju(graph,graphT,vertices,s);

        int extraWork=0;
        bool incomingEdge=false;

        set< set<int> > :: iterator upperset = s.begin();
        while(upperset != s.end())
        {
            set<int> components= *upperset;
            set<int> :: iterator it=components.begin();
            incomingEdge=false;
            while(it!=components.end())
            {
                int value =*it;
                for(int i=0;i<vertices;i++)
                {
                    if(graph[i][value] == 1 && components.find(i)==components.end())
                    {
                        incomingEdge=true;
                        break;
                    }
                }
                if(incomingEdge)
                {
                    break;
                }
                it++;
            }
            if(incomingEdge == false)
            {
                extraWork++;
            }
            upperset++;
        }

        cout << extraWork <<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *graph,int start,int n,bool *visited,set<int> &inner)
{
    visited[start]=true;
    inner.insert(start);
    for(int i=0;i<graph[start].size();i++)
    {
        int adj = graph[start][i];
        if(visited[adj]==false)
        {
            dfs(graph,adj,n,visited,inner);
        }
    }
}

long long int findMaxBanana(vector<int> *graph,int vertices,int *bananas)
{
    set< set<int> > s;

    bool *visited = new bool[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<vertices;i++)
    {
        if(visited[i]==false)
        {
            set<int> inner;
            dfs(graph,i,vertices,visited,inner);
            s.insert(inner);
        }
    }
     set< set<int> > :: iterator it = s.begin();
    set<int> :: iterator it1;
    long long int maxbanana=0;
    for(it;it!=s.end();it++)
    {
        long long int currentbanana=0;
        set<int> inner = *it;
        for(it1 = inner.begin();it1!=inner.end();it1++)
        {
            int index = *it1;
            currentbanana+=bananas[index];
        }
        cout << "cuure " <<currentbanana<<endl;
        if(currentbanana > maxbanana)
        {
            maxbanana=currentbanana;
        }
    }
    return maxbanana;
}




int main()
{
	int monkeys,edge;
    cin >> monkeys >> edge;
    vector<int> graph[monkeys];
    while(edge--)
    {
        int fv,sv;
        cin >> fv >> sv;
        fv--;sv--;
        graph[fv].push_back(sv);
        graph[sv].push_back(fv);
    }
    int bananas[monkeys];
    for(int i=0;i<monkeys;i++)
    {
        cin >> bananas[i];
    }
    cout << findMaxBanana(graph,monkeys,bananas);
	return 0;
}

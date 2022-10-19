#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;


void dfs(int start,vector<int>* edges,bool* visited,stack<int> &s,int n)
{
    visited[start]=true;
    for(int i=0;i<edges[start].size();i++)
    {
        if(!visited[edges[start][i]])
        {
            dfs(edges[start][i],edges,visited,s,n);
        }
    }
    s.push(start);
}

void dfs1(int start,vector<int>* edgesT,bool* visited,int n,unordered_set<int>* temp)
{
    visited[start]=true;
    temp->insert(start); //(*temp).insert(start).
    for(int i=0;i<edgesT[start].size();i++)
    {
        int next=edgesT[start][i];
        if(!visited[next])
        {
            dfs1(next,edgesT,visited,n,temp);
        }
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n)
{
    stack<int> s;
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,edges,visited,s,n);
        }
    }

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    unordered_set<unordered_set<int>*>* output=new  unordered_set<unordered_set<int>*>();

    while(!s.empty())
    {
        int topelement=s.top();
        s.pop();

        if(!visited[topelement])
        {
             unordered_set<int>* temp=new unordered_set<int>;
            dfs1(topelement,edgesT,visited,n,temp);
            output->insert(temp);
        }
    }
    return output;
}

int main()
{
    int n;
    cin>>n;

    vector<int>* edges=new vector<int> [n];
    vector<int>* edgesT=new vector<int> [n];

    int m;
    cin >>m;

    int starte,ende;
    while(m!=0)
    {
        cin >>starte>>ende;
        edges[starte-1].push_back(ende-1); // *(edges + indexx)
        edgesT[ende-1].push_back(starte-1);
        m--;
    }
    unordered_set<unordered_set<int>*>* conncomp=getSCC(edges,edgesT,n);
    unordered_set<unordered_set<int>*>::iterator it=conncomp->begin();
    while(it!=conncomp->end())
    {
        unordered_set<int>* comps=*it;
        unordered_set<int>::iterator it2=comps->begin();
        while(it2!=comps->end())
        {
            cout << *it2 + 1<<" ";
            it2++;
        }
        cout<<endl;
        it++;

    }

    return 0;
}

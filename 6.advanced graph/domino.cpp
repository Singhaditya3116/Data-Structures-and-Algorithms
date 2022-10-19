#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;


void dfs(int start,vector<int>* edges,bool* visited,int n,int &innercount)
{
    visited[start]=true;
    for(int i=0;i<edges[start].size();i++)
    {
        if(edges[start].size()==0)
        {
            break;
        }
            innercount++;
        if(!visited[edges[start][i]])
        {

            dfs(edges[start][i],edges,visited,n,innercount);
        }
    }
}


void getSCC(vector<int>* edges,int n)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int count=0;
    int innercount;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            innercount=0;

            dfs(i,edges,visited,n,innercount);
            if(innercount!=0)
            {
            count++;
            }
        }
    }
    cout<<count<<endl;

}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>* edges=new vector<int> [n];

        int m;
        cin >>m;

        int starte,ende;
        while(m!=0)
        {
            cin >>starte>>ende;
            edges[starte-1].push_back(ende-1);
            m--;
        }
        getSCC(edges,n);
    }

    return 0;
}

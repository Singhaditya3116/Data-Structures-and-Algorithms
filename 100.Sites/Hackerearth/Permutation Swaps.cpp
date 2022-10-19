#include<bits/stdc++.h>
using namespace std;
void connectedComponents(vector<int> **graph,int n,set<int> &s,int start,bool *visited)
{
    visited[start]=true;
    s.insert(start);
    vector<int> :: iterator it;
    for(it=graph[start]->begin();it!=graph[start]->end();it++)
    {
        int nextNode = *it;
        if(!visited[nextNode])
        {
            connectedComponents(graph,n,s,nextNode,visited);
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int arr[n],changeTo[n];
        for(int i=0;i<n;i++)
        {
            cin >>arr[i];
            --arr[i];
        }
        for(int j=0;j<n;j++)
        {
            cin >> changeTo[j];
            --changeTo[j];
        }

        vector<int> *graph[n];
        for(int i=0;i<n;i++)
        {
            graph[i]=new vector<int> (0);
        }

        while(m--)
        {
            int first,second;
            cin >>first >>second;
            first--;
            second--;
            graph[first]->push_back(second);
            graph[second]->push_back(first);
        }

        bool *visited = new bool[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }

        set< set<int> > finalset;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                set<int> s;
                connectedComponents(graph,n,s,i,visited);
                finalset.insert(s);
            }
        }

        set< set<int> > ::iterator uppersetit=finalset.begin();
        bool changeable =true;
        while(uppersetit != finalset.end())
        {
            set<int> innerSet=*uppersetit;
            set<int> ::iterator sit =innerSet.begin();
            set<int> P;
            set<int> Q;
            while(sit != innerSet.end())
            {
                int index= *sit;
                P.insert(arr[index]);
                Q.insert(changeTo[index]);
                sit++;
            }
            if(P != Q)
            {
                changeable =false;
                break;
            }
            uppersetit++;
        }
        if(changeable)
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }

    return 0;
}

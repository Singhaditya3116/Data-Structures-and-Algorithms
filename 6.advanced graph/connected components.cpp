#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

void dfs(vector<int>* edges,int start,unordered_set<int>* components,bool* visited)
{
    visited[start]=true;
    components->insert(start);

    for(int i=0;i<edges[start].size();i++)
    {
        int next=edges[start][i];
        if(!visited[next])
        {
            dfs(edges,next,components,visited);
        }
    }

}

unordered_set<unordered_set<int>*>* getcomponents(vector<int>* edges,int v)
{
    bool* visited = new bool[v]();
    unordered_set<unordered_set<int>*>* output =new unordered_set<unordered_set<int>*>();

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
           unordered_set<int>* components = new unordered_set <int>();
            dfs(edges,i,components,visited);
            output->insert(components);
        }
    }
    return output;
}



int main()
{
    int n;
    cin >>n;//vertices

    vector<int>* edges= new vector<int> [n];

    /* to print the ARRAY OF VECTORS
    for(int i=0;i<n;i++)
    {
        vector<int>:: iterator it=edges[i].begin(); //edges[0] [1,2,3,4] print then edges[1] [7,8,9]
        while(it!=edges[i].end())
        {
            cout<<*it + 1<<" ";
            it++;
        }
        cout<<endl;

    }*/


    int m;
    cin >>m;

    for(int i=0;i<m;i++)
    {
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1);
    }

      unordered_set<unordered_set<int>*>* components= getcomponents(edges,n);
      unordered_set<unordered_set<int>*>:: iterator it=components->begin();
      while(it!=components->end())
      {
          unordered_set<int>* comp=*it;
            unordered_set<int>:: iterator it1=comp->begin();
            while(it1!=comp->end())
            {
                cout<<*it1 +1<<" ";
                it1++;
            }
            cout<<endl;
            /*for(int it1=comp->begin();it1!=comp->end();it1++)
            {
                cout<<*it2 + 1<<" ";
            }
            cout<<endl;*/
            it++;
      }



    return 0;
}

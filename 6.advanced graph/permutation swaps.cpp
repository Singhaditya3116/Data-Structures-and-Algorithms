#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void dfs(int start,vector<int>* edges,bool* visited,unordered_set<int>* innerset,int n)
{
    visited[start]=true;
    innerset->insert(start);

    for(int i=0;i<edges[start].size();i++)
    {
            int next=edges[start][i];
            if(!visited[next])
            {
                dfs(next,edges,visited,innerset,n);
            }
    }

}




unordered_set<unordered_set<int>*>* ConnectedComponents(vector<int>* edges,int n)
{
    unordered_set<unordered_set<int>*>* s=new unordered_set<unordered_set<int>*>();
    bool visited[n]={false};

    for(int i=0;i<n;i++)
    {
            if(!visited[i])//call dfs and store the innerset into set
            {
                unordered_set<int>* innerset=new unordered_set<int>();
                dfs(i,edges,visited,innerset,n);
                if(!innerset->empty())
                {
                 s->insert(innerset);//after dfs executes the set is inserted in set of set
                }
            }


    }
    return s;
}

int main()
{
    int t;
    cin>>t;//no. of testcases
    while(t--)
    {
        int n,goodpairs;
        cin>>n>>goodpairs;
        int arrP[n],arrQ[n];
        for(int i=0;i<n;i++)
        {
            cin>>arrP[i];//p input
            arrP[i]--;
        }
        for(int j=0;j<n;j++)
        {
            cin >>arrQ[j];//qinput
            arrQ[j]--;
        }

        vector<int> edges[n];
        while(goodpairs!=0)//taking input in 2d array
        {
            int si,ends;
            cin >>si>>ends;
            si--;
            ends--;
            edges[si].push_back(ends);
            edges[ends].push_back(si);
            goodpairs--;
        }



        unordered_set<unordered_set<int>*>* connectedcomp=ConnectedComponents(edges,n);//getting set of set connected components

        unordered_set<unordered_set<int>*>:: iterator it;//to iterate over set of set
        it=connectedcomp->begin();
        int flag=0;
        while(it!=connectedcomp->end())
        {
            unordered_set<int>* inner = *it;
            unordered_set<int>:: iterator innerset_it=inner->begin();
            set<int> pset;//making set of p
            set<int> qset;//,aking set of q

            while(innerset_it!=inner->end())
            {
                int index=*innerset_it;//in get set of connected comp adn the index of that is inserted in P and Q from the array
                pset.insert(arrP[index]);
                qset.insert(arrQ[index]);
                innerset_it++;
            }
            if(pset!=qset)//if set are equal the we can swap else swapping cannot be done
            {
                flag=1;
                break;
            }

            it++;
            pset.clear();
            qset.clear();
        }

        if(flag==0)
        {
            cout<<"YES"<<endl;
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
    }




    return 0;
}

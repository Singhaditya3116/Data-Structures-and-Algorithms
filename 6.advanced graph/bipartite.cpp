#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool biPartite(vector<int> *edges,int vertices)
{
    unordered_set<int> s[2];
    vector<int> pending;
    s[0].insert(0);
    pending.push_back(0);

    while(pending.size()!=0)
    {
        int current = pending.back();
        pending.pop_back();
        int currentSet = s[0].count(current) > 0 ? 0 :1;
        for(int i=0;i<edges[current].size();i++)
        {
            int adj = edges[current][i];
            if(s[0].count(adj)==0 && s[1].count(adj)==0)
            {
                s[1-currentSet].insert(adj);
                pending.push_back(adj);
            }
            else
            {
                if(s[currentSet].count(adj) > 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while(t)
    {
        int v,e;
        cin >> v >> e;
        vector<int> edges[v];
        while(e--)
        {
            int fv,sv;
            cin >> fv >> sv;
            fv--;sv--;
            edges[fv].push_back(sv);
            edges[sv].push_back(fv);
        }

        bool ans=biPartite(edges,v);
        if(ans)
            cout << "Bicolorable" <<endl;
        else
            cout << "Not Bicolorable" <<endl;

        t--;
    }

}

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

void check(int *ans,int n,int &maxAffected,bool *status)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[ans[i]]++;
    }
    unordered_map<int,int> :: iterator it =m.begin();
    int maxValue=1;

    while(it!=m.end())
    {
        if(it->second > maxValue)
        {
            maxValue=(it->second);
        }
        it++;
    }

    if(maxValue > maxAffected)
    {
        maxAffected=maxValue;
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        int athelete[n];
        int ans[n];
        bool status[n];

        for(int i=0;i<n;i++)
        {
            cin >>athelete[i];
            ans[i]= (i + athelete[i]);
            status[i]=false;
            //cout <<"world "<<athelete[i] <<" "<<ans[i]<<endl;
        }
        int i=1;

        while(i!=100)
        {
            check(ans,n,maxAffected,status);
            for(int i=0;i<n;i++)
            {
                ans[i]+=athelete[i];
            }
            i++;
        }

        cout <<n-maxAffected <<" "<<maxAffected<<endl;
    }

    return 0;
}

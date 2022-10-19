#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        map<char,int> m; // map to store frequency of same kind of patient
        int stringlen ,query;
        cin >> stringlen >> query;
        for(int i=0;i<stringlen;i++)
        {
            char c;
            cin >> c;
            m[c]++;
        }

        while(query--)
        {
            int isolationCenter;
            cin >> isolationCenter;
            int pendingQueue=0;
            map<char,int> :: iterator it;
            for(it=m.begin();it!=m.end();it++)
            {
                int patient = it->second;
                int diff = patient - isolationCenter;
                if(diff > 0) // if isolation center is less then only add into queue
                {
                    pendingQueue+=diff;
                }
            }
            cout <<pendingQueue<<endl;
        }
    }
    return 0;
}

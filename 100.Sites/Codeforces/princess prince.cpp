#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >> n;
        int prince[n+1];
        int princess[n+1];
        for(int i=0;i<=n;i++)
        {
            prince[i]=0;
            princess[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int count;
            cin >>count;
            int dream[count];
            for(int j=0;j<count;j++)
            {
                cin >> dream[j];
            }
            for(int j=0;j<count;j++)
            {
                int option = dream[j];
                if(prince[option] == 0)
                {
                    prince[option]=1;
                    princess[i]=1;
                    break;
                }
            }
        }

        int marriageCount=0;
        int notMarriedIndex=0;
        int notMarriedPrinceIndex=0;
        for(int i=1;i<=n;i++)
        {
            if(princess[i]==1)
            {
                marriageCount++;
            }
            if(princess[i]==0)
            {
                notMarriedIndex=i;
            }
            if(prince[i]==0)
            {
                notMarriedPrinceIndex=i;
            }
        }
        if(notMarriedIndex == 0)
        {
            cout <<"OPTIMAL"<<endl;
        }
        else
        {
            cout << "IMPROVE" <<endl;
            cout << notMarriedIndex << " " <<notMarriedPrinceIndex <<endl;
        }
    }
    return 0;
}

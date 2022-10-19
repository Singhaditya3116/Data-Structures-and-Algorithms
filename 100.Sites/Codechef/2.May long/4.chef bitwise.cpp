#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        ll x,y,l,r;
        cin >> x >> y >>l >>r;
        ll ans=0;
        for(int i=0;i<64;i++)
        {
            int xbit = (x>>i)&1;
            int ybit = (y>>i)&1;
            if(xbit ==0 && ybit ==0)
            {
                continue;
            }
            ans =ans +pow(2,i);
        }
        cout <<ans <<endl;
    }
    return 0;

}

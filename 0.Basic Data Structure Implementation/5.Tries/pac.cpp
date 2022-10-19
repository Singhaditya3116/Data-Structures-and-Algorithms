#include<bits/stdc++.h>
# define ll long long
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {

        ll n;
        cin >>n;

        ll sum=0;
        ll limit=floor(n/2);
        for(ll i=1;i<=limit;i++)
        {
            cout <<i <<" "<<(n/i)<<endl;
            sum+=(n/i);
        }
        cout <<"sum "<<sum<<endl;

        ll diff = n - limit;

        sum+=diff;
        cout <<sum<<endl;
    }

}

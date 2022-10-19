#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        ll N;
        cin >>N;
        ll duplicate_number=N;
        ll remainder;
        ll sum=0;
        while(N!=0)
        {
            remainder=N%10;
            sum+=remainder;
            N=N/10;
        }
        if(duplicate_number%sum==0)
        {
            cout <<"1"<<endl;
        }
        else
        {
            cout <<"0"<<endl;
        }
    }

    return 0;
}

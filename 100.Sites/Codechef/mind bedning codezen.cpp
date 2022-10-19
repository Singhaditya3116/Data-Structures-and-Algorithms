#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin >>arr[i];
        }
        long long P[n];
        long long lp=1;
        for(int i=0;i<n;i++)
        {
            P[i]=lp;
            lp=lp*arr[i];
        }
        long long rp=1;
        for(int i=n-1;i>=0;i--)
        {
            P[i]=P[i]*rp;
            rp=rp*arr[i];
        }
        for(int i=0;i<n;i++)
        {
            cout <<P[i]<<" ";
        }
        cout <<endl;

    }

}

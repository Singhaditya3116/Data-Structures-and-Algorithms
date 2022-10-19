#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long int sum=0;
        for(int i=0;i<x;i++)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }


    return 0;
}


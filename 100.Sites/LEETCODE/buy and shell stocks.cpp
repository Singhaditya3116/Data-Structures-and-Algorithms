#include<iostream>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >>arr[i];

    ll maxprofit=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            maxprofit+=(arr[i]-arr[i-1]);
        }
    }
    cout <<maxprofit <<endl;

    return 0;
}

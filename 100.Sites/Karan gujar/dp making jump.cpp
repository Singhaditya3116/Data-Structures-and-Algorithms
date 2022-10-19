#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *A=new int [n+1];
    for(int i=1;i<=n;i++)
    {
        cin >>A[i];
    }
    int *dp=new int[n+1];
    dp[1]=A[1];
    dp[2]=A[1]+A[2];
    dp[3]=A[3]+max(dp[1],dp[2]);
    for(int i=4;i<=n;i++)
    {
        dp[i]=A[i]+max(dp[i-3],max(dp[i-1],dp[i-2]));
    }
    cout << dp[n];
}

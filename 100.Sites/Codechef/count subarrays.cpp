#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n; //no of element
        int A[n]; //Taking input
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }

        int dp[n]={0};
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1; // minimum increasing will be always be one at any point
            if(A[i-1] <= A[i])
            {
                dp[i]=dp[i]+dp[i-1];
            }
        }

        long long int countSubarray=0;
        for(int i=0;i<n;i++)
        {
            countSubarray+=dp[i];
        }
        cout << countSubarray <<endl;
    }

    return 0;
}

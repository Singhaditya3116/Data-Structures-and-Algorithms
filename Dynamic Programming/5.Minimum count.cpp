#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

//Bruteforce approach
int minCount(int n)
{
    if(n == 1 || n == 0)
    {
        return n;
    }
    int smallAns=INT_MAX;

    for(int i=1;i*i<=n;i++)
    {
        smallAns = min(smallAns,minCount(n-(i*i)));
    }
    return smallAns+1;
}

//Memoization

int mincount_better(int n,int *dp)
{
    if(n == 1 || n == 0)
    {
        return n;
    }

    if(dp[n] != -1) //if ans is already computed.
    {
        return dp[n];
    }

    int smallAns=INT_MAX;

    for(int i=1;i*i<=n;i++)
    {
        smallAns = min(smallAns,mincount_better(n-(i*i),dp));
    }
    dp[n]=smallAns+1;
    return smallAns+1;
}

int mincount_better(int n)
{
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    return mincount_better(n,dp);
}

//Iterative approach

int minCount_dp(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        int option1 = dp[i-1];
        int option2 = INT_MAX;

        for(int j=2;j*j<=i;j++)
        {
            option2 = min(option2,dp[i-(j*j)]);
        }

        dp[i] = min(option1,option2)+1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n)<<endl;
    cout <<mincount_better(n)<<endl;
    cout << minCount_dp(n)<<endl;
}

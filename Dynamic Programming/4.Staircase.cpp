#include<bits/stdc++.h>
using namespace std;

//Bruteforce
int staircase(int start,int n)
{
    if(start == n)
    {
        return 1;
    }

    if(start > n)
    {
        return 0;
    }

    int option1 = staircase(start+1,n);
    int option2 = staircase(start+2,n);
    int option3 = staircase(start+3,n);
    return (option1+option2+option3);
}

int staircase_better(int start,int n,int *arr)
{
    if(start == n)
    {
        arr[n]=1;
        return arr[n];
    }

    if(start > n)
    {
        return 0;
    }

    if(arr[start] != -1)
    {
        return arr[start];
    }
    int option1 = staircase_better(start+1,n,arr);
    int option2 = staircase_better(start+2,n,arr);
    int option3 = staircase_better(start+3,n,arr);

    int ans = option1+option2+option3;
    arr[start]=ans;
    return ans;

}


int staircase_better(int start,int n)
{
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    return staircase_better(start,n,arr);
}

int staircase_dp(int n)
{
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=0;
    }
    dp[n]=1;
    dp[n-1]=1;
    dp[n-2]=2;

    for(int i=n-3;i>=0;i--)
    {
        dp[i]=dp[i+1]+dp[i+2]+dp[i+3];
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    cout <<staircase(0,n) <<endl;
    cout <<staircase_better(0,n)<<endl;
    cout <<staircase_dp(n)<<endl;
}

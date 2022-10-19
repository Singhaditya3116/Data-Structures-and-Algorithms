#include<bits/stdc++.h>
using namespace std;

//Brute force approach
int lcs(string s,string t)
{
    //base case
    if(s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    //recursive call
    if(s[0] == t[0])
    {
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        int c = lcs(s.substr(1),t.substr(1));

        return max(a,max(b,c));
    }

}


//Memoization approach
int lcs_better(string s,string t ,int **ans)
{
    //Base case
    if(s.length() == 0 || t.length() == 0)
    {
        return 0;
    }

    int m = s.length();
    int n = t.length();

    if(ans[m][n] != -1)
    {
        return ans[m][n];
    }

    if(s[0] == t[0])
    {
        ans[m-1][n-1] = lcs_better(s.substr(1),t.substr(1),ans);
        ans[m][n] = 1 + ans[m-1][n-1];
    }
    else
    {
        ans[m-1][n] = lcs_better(s.substr(1),t,ans);
        ans[m][n-1] = lcs_better(s,t.substr(1),ans);
        ans[m][n] = max(ans[m][n-1],ans[m-1][n]);
    }
    return ans[m][n];
}

int lcs_better(string s,string t)
{
    int m = s.length();
    int n = t.length();

    int **ans = new int*[m+1];
    for(int i=0;i<=n;i++)
    {
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            ans[i][j]=-1;
        }
    }
    return lcs_better(s,t,ans);
}

// Iterative approach
int lcs_dp(string s , string t)
{
    int m = s.length();
    int n = t.length();

    int **dp = new int*[m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }

    for(int i=0;i<=n;i++) //Filling first row to 0.
    {
        dp[0][i]=0;
    }

    for(int i=0;i<=m;i++) //filling first column to zero.
    {
        dp[i][0]=0;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x = m-i;
            int y = n-j;

            if(s[x] == t[y])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];

}
int main()
{
    string s,t;
    cin >> s >> t;

    cout <<"Brute force "<<lcs(s,t)<<endl;
    cout <<"Memoization "<<lcs_better(s,t)<<endl;
    cout <<"Iterative "<<lcs_dp(s,t)<<endl;
    return 0;
}

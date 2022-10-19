#include<bits/stdc++.h>
using namespace std;


//Brute force
int editDistance(string s,string t)
{
    //Base case
    if(s.empty() == true && t.empty() == true)
    {
        return 0;
    }

    if(s.empty() == true || t.empty() == true)
    {
        return max(s.length(),t.length());
    }

    //Recursive calls
    if(s[0] == t[0])
    {
        return editDistance(s.substr(1),t.substr(1));
    }
    else
    {
        //insert
        string temp = s[0] + t;
        int insertOutput = editDistance(s.substr(1),temp.substr(1));

        //delete
        int deleteOutput = editDistance(s,t.substr(1));

        //replace
        int replaceOutput = editDistance(s.substr(1),t.substr(1));

        int output = min(insertOutput,min(deleteOutput,replaceOutput)) + 1;
        return output;
    }

}

//memoization

int editDistance_better(string s,string t,int **ans)
{
    //Base case
    if(s.empty() == true && t.empty() == true)
    {
        return 0;
    }

    if(s.empty() == true || t.empty() == true)
    {
        return max(s.length(),t.length());
    }

    int m = s.length();
    int n = t.length();
    if(ans[m][n] != -1)
    {
        return ans[m][n];
    }

    //Recursive calls
    if(s[0] == t[0])
    {
        ans[m-1][n-1] = editDistance_better(s.substr(1),t.substr(1),ans);
        ans[m][n] = ans[m-1][n-1];
    }
    else
    {
        //insert
        string temp = s[0] + t;
        ans[m-1][n] = editDistance_better(s.substr(1),temp.substr(1),ans);

        //delete
        ans[m][n-1] = editDistance_better(s,t.substr(1),ans);

        //replace
        ans[m-1][n-1] = editDistance_better(s.substr(1),t.substr(1),ans);

        ans[m][n] = min(ans[m-1][n],min(ans[m][n-1],ans[m-1][n-1])) + 1;
    }
    return ans[m][n];
}

int editDistance_better(string s,string t)
{
    int m = s.length();
    int n = s.length();

    int **ans = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            ans[i][j] = -1;
        }
    }

    int out =  editDistance_better(s,t,ans);

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout <<ans[i][j]<<" ";
        }
        cout <<endl;
    }

    return out;
}

//Dp approach
int editDistance_dp(string s,string t)
{
    int m = s.length();
    int n = t.length();

    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }

    for(int i=0;i<=n;i++)
    {
        dp[0][i]=i;
    }

    for(int i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x = m-i;
            int y = n-j;

            if(s[x] == t[y])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
    }

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout << dp[i][j] <<" ";
        }
        cout <<endl;
    }
    return dp[m][n];
}
int main()
{
    string s="",t="";
    cin >> s >> t;

    cout << "Bruteforce "<<editDistance(s,t)<<endl;
    cout <<"Memoizaton "<<editDistance_better(s,t)<<endl;
    cout <<"Iterative "<<editDistance_dp(s,t)<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minHealth(int **Health,int si,int sj,int ei,int ej,int **dp)
{
    if(si == ei && sj == ej)
    {
        if(Health[ei][ej] < 0)
        {
            return 1 + (-Health[ei][ej]);
        }
        else
        {
            return 1;
        }
    }

    if(si > ei || sj >ej)
    {
        return INT_MAX;
    }

    if(dp[si][sj] > -1)
    {
        return dp[si][sj];
    }

    int option1 = minHealth(Health,si,sj+1,ei,ej,dp) - Health[si][sj+1];
    int option2 = minHealth(Health,si+1,sj,ei,ej,dp) - Health[si+1][sj];
    int ans= min(option1,option2);
    if(ans < 1)
    {
        ans=1;
    }
    dp[si][sj]=ans;
    return ans;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int r,c;
        cin >> r >> c;
        int **Health = new int*[r+1];
        for(int i=0;i<=r;i++)
        {
            Health[i]=new int[c+1];
            for(int j=0;j<=c;j++)
            {
                Health[i][j]=0;
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin >> Health[i][j];
            }
        }

        int **dp = new int*[r];
        for(int i=0;i<r;i++)
        {
            dp[i]=new int[c];
            for(int j=0;j<c;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout << minHealth(Health,0,0,r-1,c-1,dp) <<endl;
    }
    return 0;
}


#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

//Brute force approach
int minCost(int **cost,int start_i,int start_j,int end_i,int end_j)
{
    if(start_i == end_i && start_j == end_j)
    {
        return cost[end_i][end_j];
    }

    if(start_i > end_i || start_j > end_j || start_i < 0 || start_j < 0)
    {
        return INT_MAX;
    }

    int option1 = minCost(cost,start_i,start_j+1,end_i,end_j);
    int option2 = minCost(cost,start_i+1,start_j+1,end_i,end_j);
    int option3 = minCost(cost,start_i+1,start_j,end_i,end_j);

    return min(option1,min(option2,option3))+cost[start_i][start_j];
}

//Memoization

int minCost_better(int **cost,int **dp,int start_i,int start_j,int end_i,int end_j)
{
    if(start_i == end_i && start_j == end_j)
    {
        return cost[end_i][end_j];
    }

    if(start_i > end_i || start_j > end_j || start_i < 0 || start_j < 0)
    {
        return INT_MAX;
    }

    if(dp[start_i][start_j] != -1) //If ans is already computed then just return.
    {
        return dp[start_i][start_j];
    }

    int option1 = minCost_better(cost,dp,start_i,start_j+1,end_i,end_j);
    int option2 = minCost_better(cost,dp,start_i+1,start_j+1,end_i,end_j);
    int option3 = minCost_better(cost,dp,start_i+1,start_j,end_i,end_j);

    int output =  min(option1,min(option2,option3))+cost[start_i][start_j];
    dp[start_i][start_j] = output;
    return output;
}


int minCost_better(int **cost,int start_i,int start_j,int end_i,int end_j)
{
    int row = end_i + 1;
    int col = end_j + 1;
    int **dp = new int*[row];
    for(int i=0;i<row;i++)
    {
        dp[i] = new int[col];
        for(int j=0;j<col;j++)
        {
            dp[i][j]=-1;
        }
    }
    return minCost_better(cost,dp,start_i,start_j,end_i,end_j);
}

//Iterative approach

int minCost_Dp(int **cost,int start_i,int start_j,int end_i,int end_j)
{
    int row = end_i + 1;
    int col = end_j + 1;
    int **dp = new int*[row];
    for(int j=0;j<row;j++)
    {
        dp[j] = new int[col];
        for(int i=0;i<col;i++)
        {
            dp[j][i] = 0;
        }
    }

    int sum=0;
    for(int i=end_i;i>=0;i--) //Filling last column
    {
        sum+=cost[i][end_j];
        dp[i][end_j]=sum;
    }

    sum=0;

    for(int j=end_j;j>=0;j--) //filling last row
    {
        sum += cost[end_i][j];
        dp[end_i][j]=sum;
    }

    for(int i=end_i-1;i>=0;i--)
    {
        for(int j = end_j-1;j>=0;j--)
        {
            int option1 = dp[i][j+1];
            int option2 = dp[i+1][j+1];
            int option3 = dp[i+1][j];

            dp[i][j]=min(option1,min(option2,option3)) + cost[i][j];
        }
    }

    return dp[0][0];
}

int main()
{
    int n,m;
    cin >> n >> m;
    int **cost = new int*[n];

    for(int i=0;i<n;i++)
    {
        cost[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            int data;
            cin >> data;
            cost[i][j]=data;
        }
    }

    cout <<minCost(cost,0,0,n-1,m-1)<<endl;
    cout <<minCost_better(cost,0,0,n-1,m-1)<<endl;
    cout <<minCost_Dp(cost,0,0,n-1,m-1)<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout <<cost[i][j]<<" ";
        }
        cout <<endl;
    }



    return 0;
}

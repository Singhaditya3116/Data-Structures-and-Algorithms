#include<bits/stdc++.h>
using namespace std;


int mincost(int **input,int si,int sj,int ei,int ej) //Normal approach
{
    if(si ==ei && sj == ej) //if only one cell present
    {
        return input[ei][ej];
    }
    if(si > ei || sj >ej) // if si crossed the max row or sj crosses the max col
    {
        return INT_MAX;
    }

    int option1 = mincost(input,si,sj+1,ei,ej); // column increment call
    int option2 = mincost(input,si+1,sj+1,ei,ej); //diagonal call
    int option3 = mincost(input,si+1,sj,ei,ej); // row increment call

    return input[si][sj] + min(option3,min(option1,option2)); //returning current cost + the minimum from all the options.
}

int Dp_mincost(int **input,int si,int sj,int ei,int ej,int **output) //Dynamic Programming approach
{
    if(si ==ei && sj == ej) //if only one cell present
    {
        return input[ei][ej];
    }
    if(si > ei || sj >ej) // if si crossed the max row or sj crosses the max col
    {
        return INT_MAX;
    }
    if(output[si][sj] > 0) // if work has already done then return it.
    {
        return output[si][sj];
    }

    int option1 = Dp_mincost(input,si,sj+1,ei,ej,output); // column increment call
    int option2 = Dp_mincost(input,si+1,sj+1,ei,ej,output); //diagonal call
    int option3 = Dp_mincost(input,si+1,sj,ei,ej,output); // row increment call

    output[si][sj] = input[si][sj] + min(option3,min(option1,option2)); //Before returning storing in the array

    return input[si][sj] + min(option3,min(option1,option2)); //returning current cost + the minimum from all the options.
}


int It_mincost(int **input,int m,int n)
{
    int **dp =new int*[m];// A 2D DP array
    for(int i=0;i<m;i++)
    {
        dp[i]=new int[n];
    }
    dp[m-1][n-1]=input[m-1][n-1];
    for(int i=m-2;i>=0;i--) //filling END rows
    {
        dp[i][n-1]=dp[i+1][n-1] + input[i][n-1];
    }

    for(int j=n-2;j>=0;j--) //filling END colums
    {
        dp[m-1][j]=dp[m-1][j+1] + input[m-1][j];
    }

    for(int i=m-2;i>=0;i--)//filling rest of the output
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j] = input[i][j] + min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    return dp[0][0];
}

int main()
{
    int row,col;
    cin >> row>>col;
    int **input = new int*[row];
    for(int i=0;i<row;i++)
    {
        input[i]=new int[col];
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> input[i][j];
        }
    }

    //int ans = mincost(input,0,0,row-1,col-1); //-----Normal approach
    //cout << ans <<endl;

   // -----DP approach--------------------------
    int ** output = new int*[row]; //a store array which will store all the work
    for(int i=0;i<row;i++)
    {
        output[i]=new int[col];
        for(int j=0;j<col;j++)
        {
            output[i][j]=0;
        }
    }

    int ans = Dp_mincost(input,0,0,row-1,col-1,output);
    cout << ans <<endl;



    //---Iterative approach
     ans= It_mincost(input,row,col);
    cout <<ans<<endl;

    return 0;
}

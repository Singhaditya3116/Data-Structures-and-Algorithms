#include<bits/stdc++.h>
#define M 1000000007;
using namespace std;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

void dfs(int **A,int n,int m,int i,int j,bool **visited,int &count)
{
    visited[i][j]=true;
    count++;
    for(int k=0;k<8;k++)
    {
        int nextx = i + dx[k];
        int nexty = j + dy[k];
        if(nextx>=0 && nextx<n && nexty>=0 && nexty<m) //checking valid
        {
            if(!visited[nextx][nexty] && A[nextx][nexty]==1)
            {
                dfs(A,n,m,nextx,nexty,visited,count);
            }
        }
    }
}

long long int findFactorial(int number)
{
    long long int ans=1;
    for(int i=1;i<=number;i++)
    {
        ans=ans*(i);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,horses;
        cin >> n >> m >>horses;
        int **A = new int*[n];
        bool **visited = new bool*[n];
        for(int i=0;i<n;i++)
        {
            A[i]=new int[m];
            visited[i]=new bool[m];
            for(int j=0;j<m;j++)
            {
                A[i][j]=0;
                visited[i][j]=false;
            }
        }

        while(horses--)
        {
            int row,col;
            cin >> row >> col;
            row--;col--;
            A[row][col]=1;
        }
        long long int photos=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i][j]==1 && !visited[i][j])
                {
                    int count=0;
                    dfs(A,n,m,i,j,visited,count);
                    if(count>0)
                    {
                        photos=photos*findFactorial(count);
                        photos=photos%M;
                    }
                }
            }
        }
        cout <<"ans "<< photos <<endl;
    }
}

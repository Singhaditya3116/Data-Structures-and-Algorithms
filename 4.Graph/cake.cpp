#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55

#include<stdio.h>
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int findbiggestpart(char cake[NMAX][NMAX],int n,int i,int j,bool **visited)
{
    cout << "s" << i <<j<<endl;
    if(i<0 && j<0 && i>=n && j>=n)
    {
        return 0;
    }
    if(visited[i][j])
    {
        return 0;
    }
    if(cake[i][j] == '0')
    {
        return 0;
    }
    visited[i][j]=true;
    int ans=0;
    for(int k=0;k<4;k++)
    {
        cout << "loop";
        int nextx=i+dx[k];
        int nexty=j+dy[k];
        cout <<nextx<<nexty;
        int option=0;
        if(nextx>=0 && nextx<n && nexty>=0 && nexty <n)
        {
            if(!visited[nextx][nexty])
            {
                cout <<"in";
                option=findbiggestpart(cake,n,nextx,nexty,visited);
                ans+=option;
            }
        }
    }
    return ans+1;
}



int solve(int n,char cake[NMAX][NMAX])
{
    int cakesize=0;
	bool **visited =new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            visited[i][j]=false;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]=='1')
            {
                cout <<"hello"<<endl;
                int ans =findbiggestpart(cake,n,i,j,visited);
                if(ans > cakesize)
                {
                    cakesize=ans;
                }
            }
        }
    }
    return cakesize;
}


char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}

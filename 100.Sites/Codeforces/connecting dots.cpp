#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int findcycle(char **graph,int n,int m,int si,int sj,int ei,int ej,char color,bool **visited,int count)
{
    //cout << "si " <<si <<" " << sj <<endl;
    visited[si][sj]=true;


    for(int i=0;i<4;i++)
    {
        int x=si+dx[i];
        int y=sj+dy[i];
        if(x>=0 && x<n && y>=0 && y<m && graph[x][y]==color)
        {
            if(count >= 4)
            {
                if(x == ei && y ==ej) return 1;
            }
            if(!visited[x][y])
            {
                int ans = findcycle(graph,n,m,x,y,ei,ej,color,visited,count+1);
                if(ans == 1)
                {
                    return 1;
                }
            }
        }
    }
    visited[si][sj]=false;
    return 0;
}

int main()
{
    int n,m;
    cin >> n >>m;
    char **graph =new char*[n];
    bool **visited =new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        graph[i]=new char[m];
        for(int j=0;j<m;j++)
        {
            cin >> graph[i][j];
        }
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ans=findcycle(graph,n,m,i,j,i,j,graph[i][j],visited,1);
            if(ans == 1)
            {
                cout << "Yes" <<endl;
                return 0;
            }
        }
    }
    cout << "No" <<endl;
    return 0;
}

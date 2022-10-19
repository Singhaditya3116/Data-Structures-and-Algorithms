#include<bits/stdc++.h>
#define ll long long int;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

using namespace std;

int kingPath(int **graph,int si,int sj,int ei,int ej,bool **visited)
{
    if(!(si >=1 && si <=8 && sj>=1 && sj<=8))
    {
        return -1;
    }
    if(visited[si][sj])
    {
        return -1;
    }
    if(si == ei && ej == sj)
    {
        return 1;
    }
    visited[si][sj]=true;
    int ans =INT_MAX;
    cout << si <<" "<<sj<<endl;

    for(int i=0;i<8;i++)
    {
        int nextx=si +dx[i];
        int nexty=sj+ dy[i];
        int option = kingPath(graph,nextx,nexty,ei,ej,visited);
        if(option == -1)
        {
            continue;
        }
        ans = min(option+1,ans);
    }
    visited[si][sj]=false;
    if(ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

int main()
{
    int **arr=new int*[9];
    bool ** visited = new bool*[9];
    for(int i=1;i<9;i++)
    {
        arr[i]=new int[9];
        visited[i]=new bool[9];
        for(int j=0;j<9;j++)
        {
            arr[i][j]=0;
            visited[i][j]=false;
        }
    }

    int si,sj,ei,ej;
    cin >> si >>sj >>ei >>ej;
    cout <<kingPath(arr,si,sj,ei,ej,visited) <<endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool SurroundDogs(char **graph,int i,int j,int row,int col)
{
    for(int k=0;k<4;k++)
    {
        int nextx=i+dx[k];
        int nexty=j+dy[k];
        if(nextx >= 0 && nextx <row && nexty>=0 && nexty <col)
        {
            if(graph[nextx][nexty] == 'S')
            {
                return false;
            }

            if(graph[nextx][nexty] == '.')
            {
                graph[nextx][nexty]='D';
            }
        }
    }
    return true;
}

int main()
{
    int row,col;
    cin >> row >> col;
    char ** graph = new char*[row];
    for(int i=0;i<row;i++)
    {
        graph[i]=new char[col];
        for(int j=0;j<col;j++)
        {
            cin >> graph[i][j];
        }
    }
    bool protect = true;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(graph[i][j] == 'W')
            {
                bool ans = SurroundDogs(graph,i,j,row,col);
                //cout <<ans <<" "<<i <<" "<<j<<endl;
                if(ans == false)
                {
                    protect = false;
                    break;
                }
            }
        }
        if(!protect) break;
    }

    if(protect)
    {
        cout << "Yes" <<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout << graph[i][j];
            }
            cout <<endl;
        }
    }
    else
    {
        cout << "No" <<endl;
    }

    return 0;
}

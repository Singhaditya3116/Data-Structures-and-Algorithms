#include<iostream>
#include<vector>
using namespace std;

int cycleCount(int **graph,int n,bool *visited,int startvertex,int currentvertex,int count)
{
    if(count >=4)
    {
        return 0;
    }
    if(startvertex == currentvertex && count==3)
    {
        return 1;
    }
	if(visited[currentvertex])
    {
        return 0;
    }
    visited[currentvertex]=true;
    //cout << currentvertex << " "<<count<<endl;
	for(int i=1;i<=n;i++)
    {
        if(graph[currentvertex][i]==1)
        {
            cout << "curr "<<currentvertex<<"calle " <<i <<endl;
            int ans = cycleCount(graph,n,visited,startvertex,i,count+1);
            if(ans == 1) return 1;
        }
    }
    return 0;
}

void makeVisitedFalse(bool *visited,int n)
{
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int **graph =new int*[n];
    int cycleNumber=0;
    for(int i=0;i<=n;i++)
    {
        graph[i]=new int [n+1];
        for(int j=0;j<=n;j++)
        {
                graph[i][j]=0;
        }
    }
    for(int i=0;i<u.size();i++)
    {
        int first = u[i];
        int second = v[i];
        graph[first][second]=1;
        graph[second][first]=1;
    }

    bool *visited = new bool[n+1];
    makeVisitedFalse(visited,n);

    cout << "hello";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
			makeVisitedFalse(visited,n);
            if(graph[i][j]==1)
            {
                cout <<"i "<<i<<"j "<<j<<endl;
            	visited[i]=true;
            	cout <<i<<endl;
               	int ans = cycleCount(graph,n,visited,i,j,1);
            	cycleNumber+=ans;
            }
        }
    }
   cout <<"ans"<< cycleNumber <<endl;
}



int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}

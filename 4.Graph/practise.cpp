#include<iostream>
#include<vector>
using namespace std;
void dfs(int** edges,int n,int startvertex,bool* visited);


int solve(int n,int e,vector<int>u,vector<int>v)
{
	int** edges = new int*[n+1];
    for(int i=1;i<=n;i++)
    {
        edges[i]=new int[n+1];
        for(int j=1;j<=n;j++)
        {
            edges[i][j]=0;
        }
    }
   int f,s;
    for(int i=0;i<e;i++)
   {
       cout << u[i] << " ";
   }
   cout<<"e"<<e<<endl;
   for(int i=0;i<e;i++)
   {
       f=u[i];
       s=v[i];
       edges[f][s]=1;
       edges[s][f]=1;
   }

    bool* visited = new bool[n+1];
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    int count = 0;

    dfs(edges,n,1,visited);
    count=1;

    for(int i=1;i<=n;i++)
    {
        cout<<"i"<<i <<" "<<visited[i];

        if(visited[i]==false)
        {
            count++;
            dfs(edges,n,i,visited);
            cout<<"count"<<count<<endl;
                for(int i=1;i<=n;i++)
                {
                    cout <<visited[i]<<" ";
                }
                cout<<endl;
        }
    }
    return count;
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

void dfs(int** edges,int n,int startvertex,bool* visited)
{
    visited[startvertex]=true;
    for(int i=1;i<=n;i++)
    {

        if(edges[startvertex][i]==1)
        {
            if(!visited[i])
            {
            dfs(edges,n,i,visited);
            }
        }
    }
}





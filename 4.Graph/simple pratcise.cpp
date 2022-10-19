char soln[11]={'C','O','D','I','N','G','N','I','N','J','A'};
void makevisitedfalse(bool** visited,int N,int M);

int findtext(char Graph[][MAXN],int N,int M,bool** visited,int row,int col,bool* ans,int k)
{
    if(ans[10]==true)
    {
        return 1;
    }

        for(int i=row-1;i<=row+1;i++)
        {
            for(int j=col-1;j<=col+1;j++)
            {
                if(i>=0&&j>=0)
                {
                    if(soln[k]==Graph[i][j])
                    {
                        if(!visited[i][j])
                        {
                            visited[i][j]=true;
                            ans[k]=true;
                            k++;
                            int c=findtext(Graph,N,M,visited,i,j,ans,k);

                            if(c!=1)
                            {

                                k--;
                                ans[k]=false;
                                visited[i][j]=false;
                                continue;
                            }
                            else{
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;

}



int solve(char Graph[][MAXN],int N, int M)
{

   bool** visited = new bool*[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=new bool[M];
        for(int j=0;j<M;j++)
        {
            visited[i][j]=false;
        }
    }
    bool* ans=new bool[11];
    for(int i=0;i<11;i++)
    {
        ans[i]=false;
    }

    int result;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(soln[0]==Graph[i][j])
            {
                 result = findtext(Graph,N,M,visited,i,j,ans,0);

                if(result!=1)
                {
                    makevisitedfalse(visited,N,M);
                        for(int i=0;i<11;i++)
                        {
                            ans[i]=false;
                          }
                    continue;
                }
                else{
                    return result;
                }
            }
        }
    }

    return result;

}


void makevisitedfalse(bool** visited,int N,int M)
{
    for(int i = 0;i < N; i++)
    {
        for(int j=0;j<M;j++)
        {
		    visited[i][j]=false;
        }
	}
}

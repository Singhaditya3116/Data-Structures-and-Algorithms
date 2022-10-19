char soln[11]={'C','O','D','I','N','G','N','I','N','J','A'};
void makevisitedfalse(bool* visited);
int k=1;
int findtext(char Graph[][MAXN],int N,int M,bool* visited,int index1,int index2)
{
    while(k!=11)
    {

    }





}



int solve(char Graph[][MAXN],int N, int M)
{

   bool* visited=new bool[N][M];
    makevisitedfalse(visited);



    for(i = 0;i < N; i++)
    {
        for(int j=0;j<M;j++)
        {
		    if(soln[i][j]=='C')
            {
                int result = findtext(Graph,N,M,visited,i,j);
                if(result==1)
                {
                    return 1;
                }
                else
                {
                    makevisitedfalse(visited);
                    continue;
                }
            }
        }
	}
    return 0;


}


void makevisitedfalse(bool* visited)
{
    for(i = 0;i < N; i++)
    {
        for(int j=0;j<M;j++)
        {
		    visited[i][j]=false;
        }
	}
}

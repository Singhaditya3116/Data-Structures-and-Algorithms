#include<bits/stdc++.h>

using namespace std;

int solve(int A[4][4],bool *rowvisited,bool *colvisited)
{
    int rowindex=0;
    int colindex=0;
    int profit=0;
    int price=100;
    int value=4;
    while(value--)
    {
        int max=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(A[i][j]>0 && !rowvisited[i] && !colvisited[j] && max<=A[i][j])
                {
                    max=A[i][j];
                    rowindex=i;
                    colindex=j;
                }
            }
        }


        profit +=(max*price);
        if(max == 0)
        {
            profit-=100;
            continue;
        }
        price-=25;
        rowvisited[rowindex]=true;
        colvisited[colindex]=true;
    }
   return profit;
}


int main()
{
    int t;
    cin >>t;
    long long int sum=0;
    int result=0;
    while(t--)
    {
        int A[4][4]={};

        int input;
        cin >>input;

        while(input--)
        {
            int movie;
            int showtime;

            char moviealpha;
            cin >> moviealpha;
            movie = (int) moviealpha - 65;
            //cout <<movie <<"fuh"<<endl;

            int option;
            cin >> option;
            switch(option)
            {
            case 12 :
                showtime=0;
                break;
            case 3 :
                showtime=1;
                break;
            case 6 :
                showtime=2;
                break;
            case 9 :
                showtime=3;
                break;
            }
            A[movie][showtime]+=1;
        }
        bool rowvisited[4]={};
        bool colvisited[4]={};

        result=solve(A,rowvisited,colvisited);
        cout <<result<<endl;
        sum+=result;
    }
    cout <<sum<<endl;
}
